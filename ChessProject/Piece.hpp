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
    void setAvailableCells(vector<string> availableCells);
    void setIsPinned(bool isPinned);
    void setCanMove(bool canMove);
    void setColor(string color);
    
    char getSymbol() const;
    vector<string> getAvailableCells() const;
    bool getIsPinned() const;
    bool getCanMove() const;
    string getColor() const;
};

#endif
