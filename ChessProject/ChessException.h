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
        if (cellName != "e0") cout<<"The name \""<<cellName<<"\" is not available: "<<reason<<".\n";
    }
};

class OptionException : public ChessException{
    string cellName;
    
public:
    OptionException(string reason, string cellName) : ChessException(reason){this->cellName = cellName;}
    
    void printMessage() const override{
        cout<<"You can't choose the cell \""<<cellName<<"\": "<<reason<<".\n";
    }
};

#endif
