#ifndef Rook_hpp
#define Rook_hpp

#include "Piece.hpp"

class Rook : public Piece{
public:
    Rook();
    
    void calcAvailableCells();
};

#endif
