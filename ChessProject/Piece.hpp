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
    string color;
    bool isFirstMove;
    
public:
    Piece();
    Piece(bool isBlack);
    
    void setSymbol(char symbol);
    void setAvailableCells(vector<string> availableCells);
    void setColor(string color);
    void setIsFirstMove(bool isFirstMove);
    
    char getSymbol() const;
    vector<string> getAvailableCells() const;
    string getColor() const;
    bool getIsFirstMove() const;
};

class Rook : public Piece{
public:
    Rook(bool isBlack) : Piece(isBlack) {
        symbol = color == "white" ? 'R' : 'r';
    }
};

class Bishop : public Piece{
public:
    Bishop(bool isBlack) : Piece(isBlack) {
        symbol = color == "white" ? 'B' : 'b';
    }
};

class Knight : public Piece{
public:
    Knight(bool isBlack) : Piece(isBlack) {
        symbol = color == "white" ? 'N' : 'n';
    }
};

class Queen : public Piece{
public:
    Queen(bool isBlack) : Piece(isBlack) {
        symbol = color == "white" ? 'Q' : 'q';
    }
};

class King : public Piece{
public:
    King(bool isBlack) : Piece(isBlack) {
        symbol = color == "white" ? 'K' : 'k';
    }
};

class Pawn : public Piece{
public:
    Pawn(bool isBlack) : Piece(isBlack) {
        symbol = color == "white" ? 'P' : 'p';
        isFirstMove = true;
    }
};

#endif
