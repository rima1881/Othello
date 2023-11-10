#include "./Game.hpp"
#include<windows.h>
#include <iostream>
#include <fstream>
#include "../Piece/Piece.hpp"
Player* Game::Player1;
Player* Game::Player2;
Board* Game::board;

std::vector<std::string> Game::initialMaps;
std::vector<std::string> Game::savedGames;
bool Game::blackTurn = false;


int Game::getInitialMapsSize(){
    return Game::initialMaps.size();
}

std::vector<std::string> Game::getSavedGames(){
    return savedGames;
}

//**************************************************************
void Game::LoadData(std::string general){

    std::ifstream reader(general);

    int mode = 0;
    std::string line;


    //I kinda don't like the way I implymented this function but I don't wanna deal with it so it is what it is
    while (true)
    {

        std::getline(reader,line);
        
        if(mode != 1 && mode != 2 && mode != 0)
            break;


        if(line[0] == '}'){
            mode++;
            continue;
        }
        

        if(mode == 1){
            initialMaps.push_back(line);
        }
        else if(mode == 2){
            savedGames.push_back(line);
        }

    }
    

}


void Game::initialization(int state,std::string name1,std::string name2){

    state--;
    std::string mapAddress = Game::initialMaps[state];

    Game::Player1 = new Player(name1, false);
    Game::Player2 = new Player(name2, true);

    Game::board = new Board();

    //Game::loadMap(mapAddress);

}


void Game::interact(){

    //Game::board -> ModifyBoard(blackTurn);


    if(blackTurn)
        Player2 -> takeTurn();
    else
        Player1 -> takeTurn();


    blackTurn = !blackTurn;

}

/*
bool Game::loadMap(std::string address){


    std::ifstream reader( "db/" +address);
    std::string line;
    Game::board = new Board();

    int size = 0;

    for(int i=0;i<8;i++){
        std::getline(reader,line);

        size = line.length();
        for(int j=0;j<size;j++){

            if(line[j] == '.'){
                (*board)[i][j] = new Position();
            }
            else if(line[j] == 'B')
                (*board)[i][j] = new Position(new Piece(true));
            else if(line[j] == 'W')
                (*board)[i][j] = new Position(new Piece(false));
            else
                throw 12;
        }

    }

    return true;
}
*/


bool Game::saveGame(){
    return false;
}

void Game::render(){

    system("cls");
    std::cout << "\n\n";
    Game::board -> Draw();

}

void Game::Start(){


    std::cout << "***********************************************";
    std::cout << "welcome to the Game:)";
    std::cout << "***********************************************";


    Game::initialization(1,"amir","reza");
    

}

void Game::Run(){

    
    Game::render();

}


void Game::FinalMSG(){

}