#include "./PlayablePosition.hpp"
#include <iostream>

PlayablePosition::PlayablePosition(){
    this -> content = nullptr;
}

bool PlayablePosition::playable(){
    return nullptr == content;
}

void PlayablePosition::setContent(Piece* content){
    this -> content = content;
}