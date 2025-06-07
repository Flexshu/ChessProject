#include "Piece.hpp"


Piece::Piece() {
    symbol = ' ';
    isPinned = false;
    canMove = false;
    color = "undefined";
    isFirstMove = false;
}

Piece::Piece(bool isBlack) {
    symbol = ' ';
    isPinned = false;
    canMove = false;
    color = isBlack ? "black" : "white";
    isFirstMove = false;
}

void Piece::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Piece::setAvailableCells(vector<string> availableCells) {
    this->availableCells = availableCells;
}

void Piece::setIsPinned(bool isPinned) { 
    this->isPinned = isPinned;
}

void Piece::setCanMove(bool canMove) { 
    this->canMove = canMove;
}

void Piece::setColor(string color) {
    this->color = color;
}

void Piece::setIsFirstMove(bool isFirstMove) {
    this->isFirstMove = isFirstMove;
}

char Piece::getSymbol() const {
    return symbol;
}

vector<string> Piece::getAvailableCells() const {
    return availableCells;
}

bool Piece::getIsPinned() const { 
    return isPinned;
}

bool Piece::getCanMove() const { 
    return canMove;
}

string Piece::getColor() const { 
    return color;
}

bool Piece::getIsFirstMove() const {
    return isFirstMove;
}
