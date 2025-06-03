#ifndef Pawn_hpp
#define Pawn_hpp

#include "Piece.hpp"

class Pawn : public Piece{
public:
    Pawn();
    
    void calcAvailableCells();
};

#endif
