#include "./PlayablePosition.hpp"
#include <iostream>

PlayablePosition::PlayablePosition(){
    this -> content = nullptr;
}

PlayablePosition::PlayablePosition(Piece* content){
    this -> content = content;
}

bool PlayablePosition::playable(){
    return nullptr == content;
}

void PlayablePosition::setContent(Piece* content){
    this -> content = content;
}