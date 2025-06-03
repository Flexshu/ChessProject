#ifndef Piece_hpp
#define Piece_hpp

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Piece{
protected:
    char symbol;
    vector<string> availableCells;
    bool isPinned;
    bool canMove;
    string color;
    
public:
    Piece();
    Piece(bool isBlack);
    
    void setSymbol(char symbol);
    void setIsPinned(bool isPinned);
    void setCanMove(bool canMove);
    void setColor(string color);
    
    char getSymbol() const;
    bool getIsPinned() const;
    bool getCanMove() const;
    string getColor() const;
    
    virtual void calcAvailableCells() = 0;
};

#endif
