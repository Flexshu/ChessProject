#include "Rook.hpp"


Rook::Rook(bool isBlack) : Piece(isBlack) { 
    symbol = color == "white" ? 'R' : 'r';
}
