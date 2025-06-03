#ifndef Knight_hpp
#define Knight_hpp

#include "Piece.hpp"

class Knight : public Piece{
public:
    Knight(bool isBlack);
    
    void calcAvailableCells();
};

#endif
