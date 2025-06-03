#include "Piece.hpp"


Piece::Piece() { 
    content = 'X';
    isPinned = false;
    canMove = false;
}

Piece::Piece(char content) { 
    this->content = content;
    isPinned = false;
    canMove = false;
}

void Piece::setContent(char content) { 
    this->content = content;
}

void Piece::setIsPinned(bool isPinned) { 
    this->isPinned = isPinned;
}

void Piece::setCanMove(bool canMove) { 
    this->canMove = canMove;
}

char Piece::getContent() const { 
    return content;
}

bool Piece::getIsPinned() const { 
    return isPinned;
}

bool Piece::getCanMove() const { 
    return canMove;
}
