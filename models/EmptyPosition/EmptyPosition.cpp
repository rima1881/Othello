#include "./EmptyPosition.hpp"
#include <iostream>

EmptyPosition::EmptyPosition(int i,int j) : Position(i,j,Content::Empty) { 
    availableDirs = {
        false,
        false,
        false,
        false,
        false,
        false,
        false,
        false
    };

}


bool EmptyPosition::Playable(){

    for(bool dir : availableDirs)
        if(dir)
            return true;


    return false;

}



void EmptyPosition::Draw(){


    if(Playable())
        std::cout << " ";
    else
        std::cout << ".";

}



void EmptyPosition::setAvailableDirs(std::array<bool,8> ConDir){
    this -> availableDirs = ConDir;
}
