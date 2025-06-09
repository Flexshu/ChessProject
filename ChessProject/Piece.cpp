#include "Piece.hpp"

Piece::Piece() {
    symbol = ' ';
    color = "undefined";
    isFirstMove = false;
}

Piece::Piece(bool isBlack) {
    symbol = ' ';
    color = isBlack ? "black" : "white";
    isFirstMove = false;
}

void Piece::setSymbol(char symbol) {
    this->symbol = symbol;
}

void Piece::setAvailableCells(vector<string> availableCells) {
    this->availableCells = availableCells;
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

string Piece::getColor() const { 
    return color;
}

bool Piece::getIsFirstMove() const {
    return isFirstMove;
}
