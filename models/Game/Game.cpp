#include "./Game.hpp"
#include<windows.h>
#include <iostream>
#include <fstream>
#include "../Piece/Piece.hpp"
#include "../UnPlayablePosition/UnPlayablePosition.hpp"

Game::Game(){

    blackTurn = false;
    endGame = 0;
    savedGamesFileAddress = "";
    initialMapsNumber = 1;

}


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


        Color c = blackTurn ? Color::Black : Color::White;
        board -> Refresh(c);

        render();
        showScores();

        std::vector<Coordinate> AV = board -> getAvailableCoordinate();

        bool hasOption = AV.size() != 0;


        if(hasOption){

            Coordinate co = blackTurn ? Player2 -> takeTurn(AV) : Player1 -> takeTurn(AV);
            board -> Put(co,c);

            endGame = 0;

        }else
            endGame++;

        if(endGame == 2)
            break;
        
        blackTurn = !blackTurn;
    }
    

}


void Game::FinalMSG(){
    std::string winner = Player1 -> getScore() > Player2 -> getScore() ? Player1 -> getName() : Player2 -> getName();

    std::cout << winner << "has won :O\n";

    showScores();
}

void Game::showScores(){

    Player1 -> setScore( board -> Count (Color::White));
    Player2 -> setScore( board -> Count (Color::Black));

    std::cout << Player1 -> getName() << ": " << Player1 -> getScore();
    std::cout << std::endl;
    std::cout << Player2 -> getName() << ": " << Player2 -> getScore();
    std::cout << std::endl;


}