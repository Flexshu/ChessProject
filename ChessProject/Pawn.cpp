#include "Pawn.hpp"


Pawn::Pawn(bool isBlack) : Piece(isBlack) {
    symbol = color == "white" ? 'P' : 'p';
    isFirstMove = true;
}
