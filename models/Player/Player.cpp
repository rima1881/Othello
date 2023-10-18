#include "./Player.hpp"

Player::Player(std::string name){
    this -> name = name;
}

std::string Player::getName(){
    return this -> name;
}