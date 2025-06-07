#include "Queen.hpp"


Queen::Queen(bool isBlack) : Piece(isBlack) { 
    symbol = color == "white" ? 'Q' : 'q';
}
