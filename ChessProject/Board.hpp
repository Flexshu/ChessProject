#ifndef Board_hpp
#define Board_hpp

#include <cctype>
#include "Cell.hpp"

class Board{
    vector<vector<Cell>> cells;
    bool endGame;
    bool turn;
    
public:
    Board();
    
    void setCell(int row, int col, Cell cell);
    Cell getCell(int row, int col) const;
    
    int findCell(string cellName) const;
    void calcAvailableCells(string cellName) const;
    
    void printBoard() const;
    void makeMove();
    void play();
};

#endif
