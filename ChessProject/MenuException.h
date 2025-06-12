#ifndef MenuException_h
#define MenuException_h

#include <iostream>
#include <string>
using namespace std;

class MenuException{
    int choice;
    
public:
    MenuException(int choice){this->choice = choice;}
    
    void printMessage(){
        cout<<choice<<" is not an available choice.\n";
    }
};

#endif
