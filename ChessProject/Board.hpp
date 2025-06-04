#ifndef Board_hpp
#define Board_hpp

#include "Cell.hpp"

class Board{
    vector<vector<Cell>> cells;
    bool endGame;
    
public:
    Board();
    
    void setCell(int row, int col, Cell cell);
    Cell getCell(int row, int col) const;
    
    void printBoard() const;
    void makeMove();
    void play();
};

#endif
