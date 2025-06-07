#include "Knight.hpp"


Knight::Knight(bool isBlack) : Piece(isBlack) { 
    symbol = color == "white" ? 'N' : 'n';
}
