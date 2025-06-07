#include "Bishop.hpp"


Bishop::Bishop(bool isBlack) : Piece(isBlack) { 
    symbol = color == "white" ? 'B' : 'b';
}
