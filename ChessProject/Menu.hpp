#ifndef Menu_hpp
#define Menu_hpp

#include "Board.hpp"
#include "MenuException.h"

namespace Menu{
class Menu{
    int totalGames;
    int whiteVictories;
    int blackVictories;
    int draws;
    
public:
    Menu();
    
    void readStats();
    void writeStats();
    void clearStats();
    
    void openMenu();
};
}

#endif
