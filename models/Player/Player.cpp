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


    std::string input;
    int i,j;
    

    while (true)
    {
        std::cout << std::endl;
        std::cout << "Enter quit to surrender or save to save the game\n";
        std::cout << this -> name << "(i j):" << std::endl;
        std::cin.ignore();
        std::getline(std::cin,input);

        if(input == "uit")
            return Coordinate(-100,-100);
        else if(input == "ave")
            return Coordinate(-50,-50);

        j = (int) input[0] - 48;
        i = (int) input[2] - 48;

        std::cout << input << "\n";
        std::cout << i << "\t" << j;
        for(Coordinate con : availablePositions)
            if(con.getI() == i && con.getJ() == j){
                endFun = true;
                break;
            }


        if(endFun)  
            break;

        std::cout << "\nCan not place on the given Coordianates\n"; 
    }

    return Coordinate(i,j);
    
}

void Player::setScore(int s){
    this -> score = s;
}

int Player::getScore(){
    return this -> score;
}