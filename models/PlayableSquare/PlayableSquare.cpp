#include "./PlayableSquare.hpp"

PlayableSquare::PlayableSquare(){

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