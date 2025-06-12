#ifndef Board_hpp
#define Board_hpp

#include <fstream>
#include "Cell.hpp"

class Board{
    vector<vector<Cell>> cells;
    bool endGame;
    bool turn;
    int result;
    
    static int gameNumber;
    
    int findCell(string cellName) const;
    bool isSameColored(int row1, int col1, int row2, int col2) const;
    bool isOppositeColored(int row1, int col1, int row2, int col2) const;
    void shootRay(vector<string>& availableCells, int a, int b, int row, int col) const;
    void shootRay(int a, int b, int row, int col);
    void calcAvailableCells(string cellName) const;
    void calcControlledCells();
    bool isCheck();
    bool canMove();
    void clearEnPassant();
    
    void checkLength(string cellName) const;
    void checkFirstSymbol(string cellName) const;
    void checkSecondSymbol(string cellName) const;
    void checkEmptiness(string cellName) const;
    void checkTurn(string cellName) const;
    void checkSameColorness(string cellName) const;
    void checkSameCell(string cellName1, string cellName2) const;
    void checkMoveLegility(string cellName1, string cellName2) const;
    void checkEnPassantAvailability(string cellName1, string cellName2);
    void checkEnPassantPlayed(string cellName);
    void checkCastlePlayed(string cellName1, string cellName2);
    void checkCheck(string cellName1, string cellName2, bool isFirstMove, Piece* taken);
    void checkEndGame(string cellName);
    void checkMate();
    void checkStalemate();
    
    void printBoard() const;
    void makeMove();
    
public:
    Board();
    
    int play();
};

#endif
