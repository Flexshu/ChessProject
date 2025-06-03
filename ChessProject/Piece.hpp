#ifndef Piece_hpp
#define Piece_hpp

#include <string>
#include <vector>
using namespace std;

class Piece{
    char content;
    vector<string> availableCells;
    bool isPinned;
    bool canMove;
    
public:
    Piece();
    Piece(char content);
    
    void setContent(char content);
    void setIsPinned(bool isPinned);
    void setCanMove(bool canMove);
    
    char getContent() const;
    bool getIsPinned() const;
    bool getCanMove() const;
    
    virtual void calcAvailableCells() = 0;
};

#endif
