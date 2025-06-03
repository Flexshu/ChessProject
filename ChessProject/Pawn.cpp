#include "Pawn.hpp"


Pawn::Pawn(bool isBlack) : Piece(isBlack) {
    symbol = color == "white" ? 'P' : 'p';
}

void Pawn::calcAvailableCells() { 
    cout<<"Coming soon\n";
}
