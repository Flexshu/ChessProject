#include "Menu.hpp"

int findGameNumber(){
    int result = 0;
    ifstream file("gameStats.txt");
    if (file.is_open()) {
        file>>result;
        file.close();
    }
    return result;
}

int Board::gameNumber = findGameNumber() + 1;

Menu::Menu() {
    totalGames = 0;
    whiteVictories = 0;
    blackVictories = 0;
    draws = 0;
}

void Menu::readStats() {
    ifstream file("gameStats.txt");
    if (file.is_open()) {
        file>>totalGames;
        file>>whiteVictories;
        file>>blackVictories;
        file>>draws;
        file.close();
    }
}

void Menu::writeStats() {
    ofstream file("gameStats.txt");
    if (file.is_open()) {
        file<<totalGames<<endl
        <<whiteVictories<<endl
        <<blackVictories<<endl
        <<draws;
        file.close();
    }
}

void Menu::clearStats() {
    *this = Menu();
    writeStats();
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
            <<"3. Clear statistics.\n"
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
            else if (menu == 3) {
                clearStats();
            }
            else throw MenuException(menu);
        }
        catch (MenuException e) {e.printMessage();}
    } while (menu != 0);
    writeStats();
}
