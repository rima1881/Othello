#include "./PlayablePosition.hpp"
#include <iostream>

PlayablePosition::PlayablePosition(){
    this -> content = nullptr;
}

PlayablePosition::PlayablePosition(Piece* content){
    this -> content = content;
}

Piece*  PlayablePosition::getContent(){
    return this -> content;
}

bool PlayablePosition::playable(){
    return nullptr == content;
}

void PlayablePosition::setContent(Piece* content){
    this -> content = content;
}

int PlayablePosition::getX(){
    return 0;
}

int PlayablePosition::getY(){
    return 0;
}

void PlayablePosition::Draw(){

    if(this -> content == nullptr)
        std::cout << " ";
    else
        content -> Draw();

}