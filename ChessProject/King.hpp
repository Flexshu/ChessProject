#ifndef King_hpp
#define King_hpp

#include "Piece.hpp"

class King : public Piece{
public:
    King();
    
    void calcAvailableCells();
};

#endif
