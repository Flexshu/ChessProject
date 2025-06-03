#ifndef Cell_hpp
#define Cell_hpp

#include <iostream>
#include <string>
using namespace std;

class Cell{
    string name;

public:
    Cell();
    Cell(string name);

    string getName() const;
};

#endif
