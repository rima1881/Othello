#include "./Game.hpp"
#include <iostream>
Player* Game::Player1;
Player* Game::Player2;
Board* Game::board;

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