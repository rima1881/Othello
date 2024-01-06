#include "./Player.hpp"
#include "../Game/Game.hpp"
#include <iostream>

Player::Player(std::string name, bool color){
    this -> name = name;
    this -> color = color;
}

bool Player::getColor(){

    return this -> color;

}


std::string Player::getName(){
    return this -> name;
}

EmptyPosition* Player::takeTurn(std::vector<EmptyPosition*> availablePositions){

    int i,j;

    while (true)
    {
        std::cout << std::endl;
        std::cout << this -> name << "(i j):" << std::endl;
        std::cin >> j >> i;

        for(EmptyPosition* pos : availablePositions)
            if(pos->getI() == i && pos->getJ() == j)
                return pos;


        std::cout << "\nCan not place on the given Coordianates\n"; 
    }

    
}

void Player::setScore(int s){
    this -> score = s;
}

int Player::getScore(){
    return this -> score;
}