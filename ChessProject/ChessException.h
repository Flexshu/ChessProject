#ifndef ChessException_h
#define ChessException_h

#include <iostream>
#include <string>
#include <cctype>
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

class MoveException : public ChessException{
    string cellName1;
    string cellName2;
    string type;
    
public:
    MoveException(string reason, string cellName1, string cellName2, char type) : ChessException(reason){
        this->cellName1 = cellName1;
        this->cellName2 = cellName2;
        if (tolower(type) == 'n') this->type = "knight";
        else if (tolower(type) == 'b') this->type = "bishop";
        else if (tolower(type) == 'r') this->type = "rook";
        else if (tolower(type) == 'p') this->type = "pawn";
        else if (tolower(type) == 'q') this->type = "queen";
        else if (tolower(type) == 'k') this->type = "king";
    }
    
    void printMessage() const override{
        cout<<"You can not move the "<<type<<" from "<<cellName1<<" to "<<cellName2<<": "<<reason<<".\n";
    }
};

#endif
