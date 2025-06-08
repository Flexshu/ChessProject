#include "Cell.hpp"


Cell::Cell() { 
    name = "undefined";
    content = nullptr;
    whiteControl = false;
    blackControl = false;
}

Cell::Cell(string name) {
    this->name = name;
    content = nullptr;
    whiteControl = false;
    blackControl = false;
}

void Cell::setName(string name) {
    this->name = name;
}

void Cell::setContent(Piece *content) {
    this->content = content;
}

void Cell::setWhiteControl(bool whiteControl) {
    this->whiteControl = whiteControl;
}

void Cell::setBlackControl(bool blackControl) {
    this->blackControl = blackControl;
}

string Cell::getName() const {
    return name;
}

Piece *Cell::getContent() const { 
    return content;
}

bool Cell::getWhiteControl() const { 
    return whiteControl;
}

bool Cell::getBlackControl() const { 
    return blackControl;
}

