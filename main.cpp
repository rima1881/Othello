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

    int option = 0;

    while(option < 1 || option > 3){

        std::cout<<"1)Start a new Game\n";;
        std::cout<<"2)Load a Game\n";
        std::cout<<"3)Exit\n";

        std::cout<<"enter operation number: ";
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


    while (true)
    {
        Game::render();
        Game::TakeTurn();
    }
    


    return 0;
}

void StartGame(){

    int initialMapsNum = Game::getInitialMapsSize();

    


    std::string name1,name2;
    std::cout << "\nplease enter player1 name: ";
    std::cin >> name1;
    std::cout << "\nplease enter player2 name: ";
    std::cin >> name2;

    int option = 0;
    while (true)
    {
        std::cout << "\nplease choose the initial map layout (1 - " << initialMapsNum << " ):";
        std::cin >> option;
        if(option <= initialMapsNum && option > 0)
            break;
        std::cout << "\nplease don't be an asshole and write a correct number MF\n";
    }
    



    Game::StartGame(option,name1,name2);

}

void LoadGame(){

    std::cout << "please make me :(";

}