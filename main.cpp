#include <iostream>
#include "./models/Game/Game.hpp"

void StartGame();
void LoadGame();


int main(){

    std::cout<<"********************************************\n";
    std::cout<< "Welcome to Game :)\n";
    std::cout<<"********************************************\n";

    Game::LoadData("db/General.txt");
    
    std::cout<<"availblale operations :\n\n";

    while(true){

    std::cout<<"1)Start a new Game\n";;
    std::cout<<"2)Load a Game\n";
    std::cout<<"3)Exit\n";

    std::cout<<"enter operation number: ";
    int option = 0;
    std::cin >> option;

    if(option == 3)
        break;

    switch (option)
    {
        case 1:
            StartGame();
            break;
        case 2:
            LoadGame();
            break;
        default:
            std::cout << "incorrect number\n";
            break;
        }

    }


    


    return 0;
}

void StartGame(){

    int initialMapsNum = Game::initialMaps.size();

    


    std::string name1,name2;
    std::cout << "\nplease enter player1 name: ";
    std::cin >> name1;
    std::cout << "\nplease enter player2 name: ";
    std::cin >> name2;


    Game::StartGame(69,name1,name2);

}

void LoadGame(){

    std::cout << "please make me :(";

}