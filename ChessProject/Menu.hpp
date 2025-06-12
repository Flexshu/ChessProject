#ifndef Menu_hpp
#define Menu_hpp

#include "Board.hpp"
#include "MenuException.h"

class Menu{
    int totalGames;
    int whiteVictories;
    int blackVictories;
    int draws;
    
public:
    Menu();
    
    void readStats();
    
    void openMenu();
};

#endif
