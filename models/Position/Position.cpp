#include "./Position.hpp"
#include <iostream>
#include "../Error/Error.hpp"

Position::Position(){
    this -> content = nullptr;
}

Position::Position(Piece* content){
    this -> content = content;
}

Piece* Position::getContent(){
    return content;
}

//has to be fixed *************************************
void Position::setContent(Piece* content){
    throw 11;
}

int Position::getX(){
    return this -> x;
}
int Position::getY(){
    return this -> y;
}
void Position::Draw(){

    //the reasoning behind this implymention is explained in piece.hpp file
    Piece::Draw(content);

}

void Position::ConvertPiece(){

    if(content == nullptr){
        throw 12;
    }


    content -> Convert();

}

bool Position::playable(){
    return false;
}