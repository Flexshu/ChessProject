#include "Board.hpp"


Board::Board() { 
    cells = vector<vector<Cell>>(8, vector<Cell>(8, Cell()));
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cells[i][j].setName(char('a' + j) + to_string(8 - i));
            cells[i][j].setContent(nullptr);
        }
    }
    for (int i=1; i<7; i+=5) {
        for (int j=0; j<8; j++) {
            cells[i][j].setContent(new Pawn());
        }
    }
    for (int i=0; i<8; i+=7) {
        for (int j=0; j<8; j+=7){
            cells[i][j].setContent(new Rook());
        }
    }
    for (int i=0; i<8; i+=7) {
        for (int j=1; j<7; j+=5){
            cells[i][j].setContent(new Knight());
        }
    }
    for (int i=0; i<8; i+=7) {
        for (int j=2; j<6; j+=3){
            cells[i][j].setContent(new Bishop());
        }
    }
    for (int i=0; i<8; i+=7) {
        cells[i][3].setContent(new Queen());
    }
    for (int i=0; i<8; i+=7) {
        cells[i][4].setContent(new King());
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
