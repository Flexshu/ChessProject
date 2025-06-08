#ifndef Cell_hpp
#define Cell_hpp

#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"
#include "ChessException.h"
using namespace std;

class Cell{
    string name;
    Piece* content;
    bool whiteControl;
    bool blackControl;

public:
    Cell();
    Cell(string name);

    void setName(string name);
    void setContent(Piece* content);
    void setWhiteControl(bool whiteControl);
    void setBlackControl(bool blackControl);
    
    string getName() const;
    Piece* getContent() const;
    bool getWhiteControl() const;
    bool getBlackControl() const;
};

#endif
