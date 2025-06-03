#include "Cell.hpp"


Cell::Cell() { 
    name = "undefined";
}

Cell::Cell(string name) {
    this->name = name;
}

string Cell::getName() const { 
    return name;
}
