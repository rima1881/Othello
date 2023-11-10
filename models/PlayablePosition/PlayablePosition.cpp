#include "./PlayablePosition.hpp"
#include <iostream>

PlayablePosition::PlayablePosition(Coordinate data,std::array<bool,8> ConDir) : co(data) , ConvertableDirections(ConDir) { }

bool PlayablePosition::playable(){
    return true;
}

bool PlayablePosition::isEmpty(){
    return true;
}

//*************************
void PlayablePosition::ConvertPiece(){
    throw 12;
}

Piece* PlayablePosition::getContent(){
    return nullptr;
}

void PlayablePosition::Draw(){
    std::cout << " ";
}

Coordinate PlayablePosition::getCoordinate(){
    return this -> co;
}

void PlayablePosition::setConvertableDirections(std::array<bool,8> ConDir){
    this -> ConvertableDirections = ConDir;
}

std::array<bool,8> PlayablePosition::getConvertableDirections(){
    return this -> ConvertableDirections;
}