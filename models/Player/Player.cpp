#include "./Player.hpp"
#include "../Game/Game.hpp"
#include <iostream>

Player::Player(std::string name, bool is_black){
    this -> name = name;
    this -> isBlack = is_black;
}

std::string Player::Color(){

    if(isBlack)
        return "Black";

    return "White";

}

bool Player::IsBlack(){
    return isBlack;
}

std::string Player::getName(){
    return this -> name;
}

void Player::takeTurn(){

    int i,j;

    while (true)
    {
        std::cout << "\n" << this -> name << ": ";
        std::cin >> i >> j;

        if((*Game::board)[i][j] -> playable()){
            (*Game::board)[i][j] = new Position(new Piece(isBlack));
            break;  
        } 

        std::cout << "can not place there !!!";
    }
    

}