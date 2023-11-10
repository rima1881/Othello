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

Coordinate Player::takeTurn(std::vector<Coordinate> availablePositions){

    bool endFun = false;

    int i,j;
    

    while (true)
    {
        std::cout << this -> name << "(i j): ";
        std::cin >> i >> j;

        for(Coordinate con : availablePositions)
            if(con.getI() == i && con.getJ() == j){
                endFun = true;
                break;
            }


        if(endFun)  
            break;

        std::cout << "Can not place on the given Coordianates\n"; 
    }

    return Coordinate(i,j);
    
}