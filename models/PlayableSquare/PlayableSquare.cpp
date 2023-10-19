#include "./PlayableSquare.hpp"
#include <iostream>

PlayableSquare::PlayableSquare(){
    this -> content = nullptr;
}

PlayableSquare::PlayableSquare(Piece* content){
    this -> content = content;
}

Piece*  PlayableSquare::getContent(){
    return this -> content;
}

bool PlayableSquare::playable(){
    return nullptr == content;
}

void PlayableSquare::setContent(Piece* content){
    this -> content = content;
}

int PlayableSquare::getX(){
    return 0;
}

int PlayableSquare::getY(){
    return 0;
}

void PlayableSquare::Draw(){

    if(this -> content == nullptr)
        std::cout << " ";
    else
        content -> Draw();

}