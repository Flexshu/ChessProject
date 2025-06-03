#ifndef Queen_hpp
#define Queen_hpp

#include "Piece.hpp"

class Queen : public Piece{
public:
    Queen(bool isBlack);
    
    void calcAvailableCells();
};

#endif
