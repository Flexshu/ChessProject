#ifndef Board_hpp
#define Board_hpp

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
    bool isSameColored(int row1, int col1, int row2, int col2) const;
    bool isOppositeColored(int row1, int col1, int row2, int col2) const;
    void calcAvailableCells(string cellName) const;
    
    void checkLength(string cellName) const;
    void checkFirstSymbol(string cellName) const;
    void checkSecondSymbol(string cellName) const;
    void checkEmptiness(string cellName) const;
    void checkTurn(string cellName) const;
    void checkSameColorness(string cellName) const;
    void checkSameCell(string cellName1, string cellName2) const;
    void checkMoveLegility(string cellName1, string cellName2) const;
    void checkEndGame(string cellName);
    
    void printBoard() const;
    void makeMove();
    void play();
};

#endif
