#include "./Game.hpp"
#include<windows.h>
#include <iostream>
#include <fstream>
#include "../Piece/Piece.hpp"
#include "../UnPlayablePosition/UnPlayablePosition.hpp"


Player* Game::Player1;
Player* Game::Player2;
Board* Game::board;
int Game::initialMapsNumber = 1;
std::string Game::savedGamesFileAddress = "";
bool Game::blackTurn = false;




//This function loads the defaults of the program
/*

In order for program to work Fully this function
need a txt file located in DB folder. if the txt
file does not exist the game will continue with
minimal options.

if the txt file is some how removed the program
gives a link to user to download it manually

*/
void Game::LoadData(std::string general){

    std::ifstream reader(general);

    //get the firstline will in general txt is an address to a file for all saved games
    std::getline(reader,savedGamesFileAddress);

    //the next line will be the number of default maps
    /*
        the resone for this way of implymention was to give the user the power
        to customize it's initial maps and number of them
    */ 
   
    std::string line;
    std::getline(reader,line);
    initialMapsNumber = stoi(line);

}


void Game::newGame(int state,std::string name1,std::string name2){

    std::string mapAddress = "initialMaps/" + std::to_string(state) + ".txt";

    Game::Player1 = new Player(name1, false);
    Game::Player2 = new Player(name2, true);

    Game::board = new Board();

    Game::loadMap(mapAddress);

}






void Game::loadMap(std::string address){


    std::ifstream reader( "db/" +address);
    std::array<std::string,8> lines;

    for(int i=0;i<8;i++)
        std::getline(reader,lines[i]);


    Game::board = new Board(lines);
}



bool Game::saveGame(){
    return false;
}

void Game::render(){

    system("cls");
    std::cout << "\n\n";
    Game::board -> Draw();

}

void Game::Start(){


    std::cout << "\n\n***********************************************\n";
    std::cout << "welcome to the Game:)\n";
    std::cout << "***********************************************\n\n";


    Game::newGame(1,"amir","reza");
    

}

void Game::Run(){

    while(true){


        Game::board -> Refresh(blackTurn ? Color::Black : Color::White);

        Game::render();

        if(blackTurn)
            Player2 -> takeTurn(Game::board -> getAvailableCoordinate());
        else
            Player1 -> takeTurn(Game::board -> getAvailableCoordinate());

        blackTurn = !blackTurn;
    }
    

}


void Game::FinalMSG(){

}