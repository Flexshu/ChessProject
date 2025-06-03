#include "Cell.hpp"


Cell::Cell() { 
    name = "undefined";
    content = nullptr;
}

Cell::Cell(string name) {
    this->name = name;
    content = nullptr;
}

void Cell::setName(string name) {
    this->name = name;
}

void Cell::setContent(Piece *content) {
    this->content = content;
}

string Cell::getName() const {
    return name;
}

Piece *Cell::getContent() const { 
    return content;
}
