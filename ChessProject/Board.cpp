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

void Board::calcAvailableCells(string cellName) const {
    vector<string> availableCells;
    int row = findCell(cellName) / 10;
    int col = findCell(cellName) % 10;
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
    bool exceptionChecker = false;
    cout<<"Pick a cell with a piece to move: ";
    getline(cin, oldCell);
    
    //checking oldCell
    if (oldCell == "e0") endGame = true;
    if (oldCell.size() != 2) throw CellNameException("does not match the length", oldCell);
    for (int i=0; i<8; i++) {
        if (oldCell[0] == char('a' + i)) exceptionChecker = true;
    }
    if (!exceptionChecker) throw CellNameException("the first symbol should be a letter from 'a' to 'h'", oldCell);
    else exceptionChecker = false;
    for (int i=0; i<8; i++) {
        if (int(oldCell[1] - '0') == 1 + i) exceptionChecker = true;
    }
    if (!exceptionChecker) throw CellNameException("the second symbol should be a number from 1 to 8", oldCell);
    else exceptionChecker = false;
    int row = findCell(oldCell) / 10;
    int col = findCell(oldCell) % 10;
    if (cells[row][col].getContent() == nullptr) throw OptionException("the chosen cell is empty", oldCell);
    if (turn) {
        if (cells[row][col].getContent()->getColor() == "black") throw OptionException("it is white to move", oldCell);
    }
    else {
        if (cells[row][col].getContent()->getColor() == "white") throw OptionException("it is black to move", oldCell);
    }
    
    cout<<"Pick a cell you want to move the piece to: ";
    getline(cin, newCell);
    
    //checking newCell
    if (newCell == oldCell) throw OptionException("you can not move a piece to a square it is on", newCell);
    if (newCell == "e0") endGame = true;
    if (newCell.size() != 2) throw CellNameException("name does not match the length", newCell);
    for (int i=0; i<8; i++) {
        if (newCell[0] == char('a' + i)) exceptionChecker = true;
    }
    if (!exceptionChecker) throw CellNameException("the first symbol should be a letter from 'a' to 'h'", newCell);
    else exceptionChecker = false;
    for (int i=0; i<8; i++) {
        if (int(newCell[1] - '0') == 1 + i) exceptionChecker = true;
    }
    if (!exceptionChecker) throw CellNameException("the second symbol should be a number from 1 to 8", newCell);
    else exceptionChecker = false;
    row = findCell(newCell) / 10;
    col = findCell(newCell) % 10;
    if (cells[row][col].getContent() != nullptr) {
        if (turn) {
            if (cells[row][col].getContent()->getColor() == "white") throw CellNameException("you can not take the same-colored piece", newCell);
        }
        else {
            if (cells[row][col].getContent()->getColor() == "black") throw CellNameException("you can not take the same-colored piece", newCell);
        }
    }
    
    bool found = false;
    
    //making a move
    for (int i=0; i<8; i++) {
        if (found) break;
        for (int j=0; j<8; j++) {
            if (cells[i][j].getName() == oldCell) {
                for (int t=0; t<8; t++) {
                    if (found) break;
                    for (int f=0; f<8; f++) {
                        if (cells[t][f].getName() == newCell) {
                            cells[t][f].setContent(cells[i][j].getContent());
                            cells[i][j].setContent(nullptr);
                            found = true;
                            break;
                        }
                    }
                }
                break;
            }
        }
    }
    turn = !turn;
}

void Board::play() { 
    do {
        try {
            this->printBoard();
            this->makeMove();
        }
        catch (CellNameException e) {
            e.printMessage();
        }
        catch (OptionException e){
            e.printMessage();
        }
    } while (!endGame);
}
