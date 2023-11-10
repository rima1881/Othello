#include "./PlayablePosition.hpp"
#include <iostream>

PlayablePosition::PlayablePosition(){

}

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