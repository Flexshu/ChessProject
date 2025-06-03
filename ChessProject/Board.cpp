#include "Board.hpp"


Board::Board() { 
    cells = vector<vector<Cell>>(8, vector<Cell>(8, Cell()));
}

void Board::setCell(int row, int col, Cell cell) {
    cells[row][col] = cell;
}

Cell Board::getCell(int row, int col) const {
    return cells[row][col];
}

void Board::printBoard() const { 
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            cout<<"+---";
        }
        cout<<"+\n";
        for (int j=0; j<8; j++) {
            cout<<"|   ";
        }
        cout<<"|\n";
    }
    for (int j=0; j<8; j++) {
        cout<<"+---";
    }
    cout<<"+\n";
}
