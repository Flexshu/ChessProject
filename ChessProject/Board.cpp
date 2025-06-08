#include "Board.hpp"

Board::Board() { 
    cells = vector<vector<Cell>>(8, vector<Cell>(8, Cell()));
    endGame = false;
    turn = 1;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cells[i][j].setName(char('a' + j) + to_string(8 - i));
            cells[i][j].setContent(nullptr);
        }
    }
    for (int i=1; i<7; i+=5) {
        for (int j=0; j<8; j++) {
            cells[i][j].setContent(new Pawn(i == 1));
        }
    }
    for (int i=0; i<8; i+=7) {
        for (int j=0; j<8; j+=7){
            cells[i][j].setContent(new Rook(i == 0));
        }
    }
    for (int i=0; i<8; i+=7) {
        for (int j=1; j<7; j+=5){
            cells[i][j].setContent(new Knight(i == 0));
        }
    }
    for (int i=0; i<8; i+=7) {
        for (int j=2; j<6; j+=3){
            cells[i][j].setContent(new Bishop(i == 0));
        }
    }
    for (int i=0; i<8; i+=7) {
        cells[i][3].setContent(new Queen(i == 0));
    }
    for (int i=0; i<8; i+=7) {
        cells[i][4].setContent(new King(i == 0));
    }
}

void Board::setCell(int row, int col, Cell cell) {
    cells[row][col] = cell;
}

Cell Board::getCell(int row, int col) const {
    return cells[row][col];
}

int Board::findCell(string cellName) const {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (cells[i][j].getName() == cellName) {
                return i * 10 + j;
            }
        }
    }
    return -1;
}

bool Board::isSameColored(int row1, int col1, int row2, int col2) const {
    if (cells[row1][col1].getContent() != nullptr && cells[row2][col2].getContent() != nullptr) {
        if (cells[row1][col1].getContent()->getColor() == cells[row2][col2].getContent()->getColor()) return true;
        else return false;
    }
    else return false;
}

bool Board::isOppositeColored(int row1, int col1, int row2, int col2) const {
    if (cells[row1][col1].getContent() != nullptr && cells[row2][col2].getContent() != nullptr) {
        if (cells[row1][col1].getContent()->getColor() != cells[row2][col2].getContent()->getColor()) return true;
        else return false;
    }
    else return false;
}

void Board::shootRay(vector<string> &availableCells, int a, int b, int row, int col) const {
    for (int i=1; i<8; i++) {
        if (row + i * b > 7 || row + i * b < 0 || col + i * a > 7 || col + i * a < 0) break;
        if (isSameColored(row, col, row + i * b, col + i * a)) break;
        if (isOppositeColored(row, col, row + i * b, col + i * a)){
            char c = char(cells[row][col].getName()[0] + i * a);
            int n = cells[row][col].getName()[1] - '0' - i * b;
            availableCells.push_back(string(1, c) + to_string(n));
            break;
        }
        char c = char(cells[row][col].getName()[0] + i * a);
        int n = cells[row][col].getName()[1] - '0' - i * b;
        availableCells.push_back(string(1, c) + to_string(n));
    }
}

void Board::shootRay(int a, int b, int row, int col) {
    for (int i=1; i<8; i++) {
        if (row + i * b > 7 || row + i * b < 0 || col + i * a > 7 || col + i * a < 0) break;
        if (isSameColored(row, col, row + i * b, col + i * a) || isOppositeColored(row, col, row + i * b, col + i * a)){
            if (row + i * b <= 7 && row + i * b >= 0 && col + i * a <= 7 && col + i * a >= 0) {
                if (cells[row][col].getContent()->getColor() == "white") {
                    cells[row + i * b][col + i * a].setWhiteControl(true);
                }
                if (cells[row][col].getContent()->getColor() == "black") {
                    cells[row + i * b][col + i * a].setBlackControl(true);
                }
            }
            break;
        }
        if (row + i * b <= 7 && row + i * b >= 0 && col + i * a <= 7 && col + i * a >= 0) {
            if (cells[row][col].getContent()->getColor() == "white") {
                cells[row + i * b][col + i * a].setWhiteControl(true);
            }
            if (cells[row][col].getContent()->getColor() == "black") {
                cells[row + i * b][col + i * a].setBlackControl(true);
            }
        }
    }
}

void Board::calcAvailableCells(string cellName) const {
    vector<string> availableCells;
    int row = findCell(cellName) / 10;
    int col = findCell(cellName) % 10;
    if (tolower(cells[row][col].getContent()->getSymbol()) == 'n') {
        for (int i=-2; i<3; i+=4) {
            for (int j=-1; j<2; j+=2) {
                char c1 = char(cells[row][col].getName()[0] + i);
                int i1 = cells[row][col].getName()[1] - '0' + j;
                char c2 = char(cells[row][col].getName()[0] + j);
                int i2 = cells[row][col].getName()[1] - '0' + i;
                if (c1 >= 'a' && c1 <= 'h' && i1 >= 1 && i1 <= 8) availableCells.push_back(string(1, c1) + to_string(i1));
                if (c2 >= 'a' && c2 <= 'h' && i2 >= 1 && i2 <= 8) availableCells.push_back(string(1, c2) + to_string(i2));
            }
        }
    }
    else if (tolower(cells[row][col].getContent()->getSymbol()) == 'r') {
        shootRay(availableCells, 0, 1, row, col);
        shootRay(availableCells, 0, -1, row, col);
        shootRay(availableCells, 1, 0, row, col);
        shootRay(availableCells, -1, 0, row, col);
    }
    else if (tolower(cells[row][col].getContent()->getSymbol()) == 'b') {
        shootRay(availableCells, 1, 1, row, col);
        shootRay(availableCells, 1, -1, row, col);
        shootRay(availableCells, -1, 1, row, col);
        shootRay(availableCells, -1, -1, row, col);
    }
    else if (tolower(cells[row][col].getContent()->getSymbol()) == 'q') {
        shootRay(availableCells, 0, 1, row, col);
        shootRay(availableCells, 0, -1, row, col);
        shootRay(availableCells, 1, 0, row, col);
        shootRay(availableCells, -1, 0, row, col);
        shootRay(availableCells, 1, 1, row, col);
        shootRay(availableCells, 1, -1, row, col);
        shootRay(availableCells, -1, 1, row, col);
        shootRay(availableCells, -1, -1, row, col);
    }
    else if (tolower(cells[row][col].getContent()->getSymbol()) == 'k') {
        for (int i=-1; i<2; i++) {
            for (int j=-1; j<2; j++) {
                char c = char(cells[row][col].getName()[0] + i);
                int n = cells[row][col].getName()[1] - '0' + j;
                if (c >= 'a' && c <= 'h' && n >= 1 && n <= 8) availableCells.push_back(string(1, c) + to_string(n));
            }
        }
    }
    else if (cells[row][col].getContent()->getSymbol() == 'P') {
        char c = char(cells[row][col].getName()[0]);
        int n = cells[row][col].getName()[1] - '0' + 1;
        if (cells[row - 1][col].getContent() == nullptr) {
            availableCells.push_back(string(1, c) + to_string(n));
            if (cells[row][col].getContent()->getIsFirstMove() && cells[row - 2][col].getContent() == nullptr){
                int n2 = cells[row][col].getName()[1] - '0' + 2;
                availableCells.push_back(string(1, c) + to_string(n2));
            }
        }
        if (col != 7) {
            if (isOppositeColored(row, col, row - 1, col + 1)){
                char c2 = char(cells[row][col].getName()[0] + 1);
                int n2 = cells[row][col].getName()[1] - '0' + 1;
                availableCells.push_back(string(1, c2) + to_string(n2));
            }
        }
        if (col != 0) {
            if (isOppositeColored(row, col, row - 1, col - 1)){
                char c2 = char(cells[row][col].getName()[0] - 1);
                int n2 = cells[row][col].getName()[1] - '0' + 1;
                availableCells.push_back(string(1, c2) + to_string(n2));
            }
        }
    }
    else if (cells[row][col].getContent()->getSymbol() == 'p') {
        char c = char(cells[row][col].getName()[0]);
        int n = cells[row][col].getName()[1] - '0' - 1;
        if (cells[row + 1][col].getContent() == nullptr) {
            availableCells.push_back(string(1, c) + to_string(n));
            if (cells[row][col].getContent()->getIsFirstMove() && cells[row + 2][col].getContent() == nullptr){
                int n2 = cells[row][col].getName()[1] - '0' - 2;
                availableCells.push_back(string(1, c) + to_string(n2));
            }
        }
        if (col != 7) {
            if (isOppositeColored(row, col, row + 1, col + 1)){
                char c2 = char(cells[row][col].getName()[0] + 1);
                int n2 = cells[row][col].getName()[1] - '0' - 1;
                availableCells.push_back(string(1, c2) + to_string(n2));
            }
        }
        if (col != 0) {
            if (isOppositeColored(row, col, row + 1, col - 1)){
                char c2 = char(cells[row][col].getName()[0] - 1);
                int n2 = cells[row][col].getName()[1] - '0' - 1;
                availableCells.push_back(string(1, c2) + to_string(n2));
            }
        }
    }
    cells[row][col].getContent()->setAvailableCells(availableCells);
}

void Board::calcControlledCells() {
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cells[i][j].setWhiteControl(false);
            cells[i][j].setBlackControl(false);
        }
    }
    for (int row=0; row<8; row++) {
        for (int col=0; col<8; col++) {
            if (cells[row][col].getContent() != nullptr) {
                if (tolower(cells[row][col].getContent()->getSymbol()) == 'n') {
                    for (int i=-2; i<3; i+=4) {
                        for (int j=-1; j<2; j+=2) {
                            if (row + i <= 7 && row + i >= 0 && col + j <= 7 && col + j >= 0) {
                                if (cells[row][col].getContent()->getColor() == "white") {
                                    cells[row + i][col + j].setWhiteControl(true);
                                }
                                if (cells[row][col].getContent()->getColor() == "black") {
                                    cells[row + i][col + j].setBlackControl(true);
                                }
                            }
                            if (row + j <= 7 && row + j >= 0 && col + i <= 7 && col + i >= 0) {
                                if (cells[row][col].getContent()->getColor() == "white") {
                                    cells[row + j][col + i].setWhiteControl(true);
                                }
                                if (cells[row][col].getContent()->getColor() == "black") {
                                    cells[row + j][col + i].setBlackControl(true);
                                }
                            }
                        }
                    }
                }
                if (tolower(cells[row][col].getContent()->getSymbol()) == 'r') {
                    shootRay(0, 1, row, col);
                    shootRay(0, -1, row, col);
                    shootRay(1, 0, row, col);
                    shootRay(-1, 0, row, col);
                }
                if (tolower(cells[row][col].getContent()->getSymbol()) == 'b') {
                    shootRay(1, 1, row, col);
                    shootRay(1, -1, row, col);
                    shootRay(-1, 1, row, col);
                    shootRay(-1, -1, row, col);
                }
                if (tolower(cells[row][col].getContent()->getSymbol()) == 'q') {
                    shootRay(0, 1, row, col);
                    shootRay(0, -1, row, col);
                    shootRay(1, 0, row, col);
                    shootRay(-1, 0, row, col);
                    shootRay(1, 1, row, col);
                    shootRay(1, -1, row, col);
                    shootRay(-1, 1, row, col);
                    shootRay(-1, -1, row, col);
                }
                if (tolower(cells[row][col].getContent()->getSymbol()) == 'k') {
                    for (int i=-1; i<2; i++) {
                        for (int j=-1; j<2; j++) {
                            if (row + i <= 7 && row + i >= 0 && col + j <= 7 && col + j >= 0) {
                                if (cells[row][col].getContent()->getColor() == "white") {
                                    cells[row + i][col + j].setWhiteControl(true);
                                }
                                if (cells[row][col].getContent()->getColor() == "black") {
                                    cells[row + i][col + j].setBlackControl(true);
                                }
                            }
                        }
                    }
                }
                if (cells[row][col].getContent()->getSymbol() == 'P') {
                    if (row - 1 >= 0 && col + 1 <= 7) {
                        if (cells[row][col].getContent()->getColor() == "white") {
                            cells[row - 1][col + 1].setWhiteControl(true);
                        }
                        if (cells[row][col].getContent()->getColor() == "black") {
                            cells[row - 1][col + 1].setBlackControl(true);
                        }
                    }
                    if (row - 1 >= 0 && col - 1 >= 0) {
                        if (cells[row][col].getContent()->getColor() == "white") {
                            cells[row - 1][col - 1].setWhiteControl(true);
                        }
                        if (cells[row][col].getContent()->getColor() == "black") {
                            cells[row - 1][col - 1].setBlackControl(true);
                        }
                    }
                }
                if (cells[row][col].getContent()->getSymbol() == 'p') {
                    if (row + 1 <= 7 && col + 1 <= 7) {
                        if (cells[row][col].getContent()->getColor() == "white") {
                            cells[row + 1][col + 1].setWhiteControl(true);
                        }
                        if (cells[row][col].getContent()->getColor() == "black") {
                            cells[row + 1][col + 1].setBlackControl(true);
                        }
                    }
                    if (row + 1 <= 7 && col - 1 >= 0) {
                        if (cells[row][col].getContent()->getColor() == "white") {
                            cells[row + 1][col - 1].setWhiteControl(true);
                        }
                        if (cells[row][col].getContent()->getColor() == "black") {
                            cells[row + 1][col - 1].setBlackControl(true);
                        }
                    }
                }
            }
        }
    }
}

void Board::checkLength(string cellName) const {
    if (cellName.size() != 2) throw CellNameException("does not match the length", cellName);
}

void Board::checkFirstSymbol(string cellName) const {
    bool exceptionChecker = false;
    for (int i=0; i<8; i++) {
        if (cellName[0] == char('a' + i)) exceptionChecker = true;
    }
    if (!exceptionChecker) throw CellNameException("the first symbol should be a letter from 'a' to 'h'", cellName);
}

void Board::checkSecondSymbol(string cellName) const {
    bool exceptionChecker = false;
    for (int i=0; i<8; i++) {
        if (int(cellName[1] - '0') == 1 + i) exceptionChecker = true;
    }
    if (!exceptionChecker) throw CellNameException("the second symbol should be a number from 1 to 8", cellName);
}

void Board::checkEmptiness(string cellName) const {
    int row = findCell(cellName) / 10;
    int col = findCell(cellName) % 10;
    if (cells[row][col].getContent() == nullptr) throw OptionException("the chosen cell is empty", cellName);
}

void Board::checkTurn(string cellName) const {
    int row = findCell(cellName) / 10;
    int col = findCell(cellName) % 10;
    if (turn) {
        if (cells[row][col].getContent()->getColor() == "black") throw OptionException("it is white to move", cellName);
    }
    else {
        if (cells[row][col].getContent()->getColor() == "white") throw OptionException("it is black to move", cellName);
    }
}

void Board::checkSameColorness(string cellName) const {
    int row = findCell(cellName) / 10;
    int col = findCell(cellName) % 10;
    if (cells[row][col].getContent() != nullptr) {
        if (turn) {
            if (cells[row][col].getContent()->getColor() == "white") throw OptionException("you can not take the same-colored piece", cellName);
        }
        else {
            if (cells[row][col].getContent()->getColor() == "black") throw OptionException("you can not take the same-colored piece", cellName);
        }
    }
}

void Board::checkSameCell(string cellName1, string cellName2) const {
    if (cellName1 == cellName2) throw OptionException("you can not move a piece to a square it is on", cellName2);
}

void Board::checkMoveLegility(string cellName1, string cellName2) const {
    bool exceptionChecker = false;
    int row = findCell(cellName1) / 10;
    int col = findCell(cellName1) % 10;
    calcAvailableCells(cellName1);
    if (cells[row][col].getContent()->getAvailableCells().size() == 0) throw MoveException("pieces do not move so", cellName1, cellName2, cells[row][col].getContent()->getSymbol());
    for (int i=0; i<cells[row][col].getContent()->getAvailableCells().size(); i++) {
        if (cells[row][col].getContent()->getAvailableCells()[i] == cellName2) {exceptionChecker = true;}
    }
    if (!exceptionChecker) throw MoveException("pieces do not move so", cellName1, cellName2, cells[row][col].getContent()->getSymbol());
}

void Board::checkEndGame(string cellName) {
    if (cellName == "e0") endGame = true;
}

void Board::printBoard() const {
    int row = 8;
    for (int i=0; i<8; i++) {
        cout<<"  ";
        for (int j=0; j<8; j++) {
            cout<<"+---";
        }
        cout<<"+\n";
        cout<<row - i<<" ";
        for (int j=0; j<8; j++) {
            if (cells[i][j].getContent() == nullptr) {
                cout<<"|   ";
            }
            else{
                cout<<"| "<<cells[i][j].getContent()->getSymbol()<<" ";
            }
        }
        cout<<"|\n";
    }
    cout<<"  ";
    for (int i=0; i<8; i++) {
        cout<<"+---";
    }
    cout<<"+\n  ";
    char file = 'a';
    for (int i=0; i<8; i++) {
        cout<<"  "<<char(file + i)<<" ";
    }
    cout<<endl;
}

void Board::makeMove() { 
    string oldCell, newCell;
    cout<<"Pick a cell with a piece to move: ";
    getline(cin, oldCell);
    
    checkEndGame(oldCell);
    checkLength(oldCell);
    checkFirstSymbol(oldCell);
    checkSecondSymbol(oldCell);
    checkEmptiness(oldCell);
    checkTurn(oldCell);
    
    cout<<"Pick a cell you want to move the piece to: ";
    getline(cin, newCell);
    
    checkSameCell(oldCell, newCell);
    checkEndGame(newCell);
    checkLength(newCell);
    checkFirstSymbol(newCell);
    checkSecondSymbol(newCell);
    checkSameColorness(newCell);
    checkMoveLegility(oldCell, newCell);
    
    int row1 = findCell(oldCell) / 10;
    int col1 = findCell(oldCell) % 10;
    int row2 = findCell(newCell) / 10;
    int col2 = findCell(newCell) % 10;
    cells[row1][col1].getContent()->setIsFirstMove(false);
    cells[row2][col2].setContent(cells[row1][col1].getContent());
    cells[row1][col1].setContent(nullptr);
    turn = !turn;
    calcControlledCells();
}

void Board::play() { 
    do {
        try {
            this->printBoard();
            this->makeMove();
        }
        catch (CellNameException e) {e.printMessage();}
        catch (OptionException e) {e.printMessage();}
        catch (MoveException e) {e.printMessage();}
    } while (!endGame);
}
