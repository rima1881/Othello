#include "./Game.hpp"
#include<windows.h>
#include <iostream>

Game::Game(){

    color = true;
    endGame = 0;
    board;

}


void Game::newGame(std::string name1,std::string name2){


    Player1 = new Player(name1, true);
    Player2 = new Player(name2, false);

    board = new Board();
}



void Game::render(){

    system("cls");
    std::cout << "\n\n";
    Game::board->Draw();

}

void Game::Menu(){


    std::cout << "\n\n***********************************************\n";
    std::cout << "welcome to the Game:)\n";
    std::cout << "***********************************************\n\n";


    std::cout << std::endl;
    std::cout << "Please Enter Player1 name:";
    std::string name1 ,name2;
    std::cin >> name1;
    std::cout << "Please Enter Player2 name:";
    std::cin >> name2;

          
    newGame(name1,name2);    

}


    
void Game::Run(){

    while(true){

        board->Refresh(color);

        render();
        showScores();

        std::vector<EmptyPosition*> AV = board->getAvailableCoordinate();

        bool hasOption = AV.size() != 0;


        if(hasOption){

            EmptyPosition* pos = color ? Player2 -> takeTurn(AV) : Player1 -> takeTurn(AV);   
            board->Put(pos,color);
            endGame = 0;

        }else
            endGame++;


        if(endGame == 2)
            break;
                
        color = !color;
    }
    

}


void Game::FinalMSG(){
    std::string winner = Player1 -> getScore() > Player2 -> getScore() ? Player1 -> getName() : Player2 -> getName();

    std::cout << winner << "has won :O\n";

    showScores();
}

void Game::showScores(){

    Player1 -> setScore( board->Count (true));
    Player2 -> setScore( board->Count (false));

    std::cout << Player1 -> getName() << ": " << Player1 -> getScore();
    std::cout << std::endl;
    std::cout << Player2 -> getName() << ": " << Player2 -> getScore();
    std::cout << std::endl;


}