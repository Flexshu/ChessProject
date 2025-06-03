#include "King.hpp"


King::King(bool isBlack) : Piece(isBlack) { 
    symbol = color == "white" ? 'K' : 'k';
}

void King::calcAvailableCells() { 
    cout<<"Coming soon\n";
}
