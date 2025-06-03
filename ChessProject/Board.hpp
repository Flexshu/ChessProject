#ifndef Board_hpp
#define Board_hpp

#include <iostream>
#include <string>
#include <vector>
#include "Cell.hpp"
using namespace std;

class Board{
    vector<vector<Cell>> cells;
    
public:
    Board();
    
    void setCell(int row, int col, Cell cell);
    Cell getCell(int row, int col) const;
    
    void printBoard() const;
};

#endif
