#include "Board.hpp"


Board::Board() { 
    cells = vector<vector<Cell>>(8, vector<Cell>(8, Cell()));
    endGame = false;
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
    cout<<"Pick a cell you want the piece to move to: ";
    getline(cin, newCell);
    if (oldCell == "e0" || newCell == "e0") endGame = true;
    bool found = false;
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
}

void Board::play() { 
    do {
        this->printBoard();
        this->makeMove();
    } while (!endGame);
}

