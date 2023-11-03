#include "./Game.hpp"
#include <iostream>
#include <fstream>
#include "../Piece/Piece.hpp"
Player* Game::Player1;
Player* Game::Player2;
Board* Game::board;

std::vector<std::string> Game::initialMaps;
std::vector<std::string> Game::savedGames;

void Game::LoadData(std::string general){

    std::ifstream reader(general);

    int mode = 0;
    std::string line;

    std::getline(reader,line);
    Piece::BlackSymbol = line[0];

    std::getline(reader, line);
    Piece::WhiteSymbol = line[0];


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


void Game::StartGame(int state,std::string name1,std::string name2){
    Game::Player1 = new Player(name1);
    Game::Player2 = new Player(name2);
    Game::board = new Board(state);

    Game::render();
}

bool Game::Load(){
    Game::Player1 = new Player("fuck1");
    Game::Player2 = new Player("fuck2");
    Game::board = new Board(69);
    return false;
}

bool Game::SaveGame(){
    return false;
}

void Game::render(){

    Game::board -> Draw();

    int randomMF;

    std::cin >> randomMF;
    std::cin >> randomMF;

}