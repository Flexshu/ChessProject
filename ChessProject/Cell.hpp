#ifndef Cell_hpp
#define Cell_hpp

#include "Piece.hpp"
#include "ChessException.h"

class Cell{
    string name;
    Piece* content;
    bool whiteControl;
    bool blackControl;
    bool canEnPassant;

public:
    Cell();
    ~Cell();

    void setName(string name);
    void setContent(Piece* content);
    void setWhiteControl(bool whiteControl);
    void setBlackControl(bool blackControl);
    void setCanEnPassant(bool canEnPassant);
    
    string getName() const;
    Piece* getContent() const;
    bool getWhiteControl() const;
    bool getBlackControl() const;
    bool getCanEnPassant() const;
};

#endif
