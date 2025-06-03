#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

class Knight : public Piece{
public:
    Knight();
    
    void calcAvailableCells();
};

#endif
