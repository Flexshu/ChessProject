#ifndef Bishop_hpp
#define Bishop_hpp

#include "Piece.hpp"

class Bishop : public Piece{
public:
    Bishop();
    
    void calcAvailableCells();
};

#endif
