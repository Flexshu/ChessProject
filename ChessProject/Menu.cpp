#include "Menu.hpp"

Menu::Menu() { 
    totalGames = 0;
    whiteVictories = 0;
    blackVictories = 0;
    draws = 0;
}

void Menu::readStats() { 
    
}

void Menu::openMenu() { 
    readStats();
    int menu = -1;
    do {
        try {
            cout<<"\nPick an action:\n"
            <<"0. Exit.\n"
            <<"1. Play a new game.\n"
            <<"2. View statistics.\n"
            <<"Enter your choice: ";
            cin>>menu;
            cout<<endl;
            if (menu == 0) {}
            else if (menu == 1) {
                cin.ignore();
                int result = Board().play();
                if (result == 0) draws++;
                else if (result == 1) whiteVictories++;
                else if (result == 2) blackVictories++;
                else{}
                totalGames++;
            }
            else if (menu == 2) {
                cout<<"Total games: "<<totalGames<<".\n"
                <<"White victories: "<<whiteVictories<<".\n"
                <<"Black victories: "<<blackVictories<<".\n"
                <<"Draws: "<<draws<<".\n";
            }
            else throw MenuException(menu);
        }
        catch (MenuException e) {e.printMessage();}
    } while (menu != 0);
}
