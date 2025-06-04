#ifndef ChessException_h
#define ChessException_h

#include <iostream>
#include <string>
using namespace std;

class ChessException{
protected:
    string reason;
    
public:
    ChessException(string reason){this->reason = reason;}
    
    virtual void printMessage() const = 0;
};

class CellNameException : public ChessException{
    string cellName;
    
public:
    CellNameException(string reason, string cellName) : ChessException(reason){this->cellName = cellName;}
    
    void printMessage() const override{
        if (cellName != "e0") cout<<"Name \""<<cellName<<"\" is not available: "<<reason<<".\n";
    }
};

class EmptyCellException : public ChessException{
    string cellName;
    
public:
    EmptyCellException(string reason, string cellName) : ChessException(reason){this->cellName = cellName;}
    
    void printMessage() const override{cout<<"Cell "<<cellName<<" is "<<reason<<".\n";}
};

#endif
