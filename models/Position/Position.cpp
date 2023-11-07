#include "./Position.hpp"
#include <iostream>
#include "../Error/Error.hpp"

Position::Position(){
    this -> data = nullptr;

}

Position::Position(Piece* content){
    this -> data = content;
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
    Piece::Draw(data);


}

void Position::ConvertPiece(){

    if(data == nullptr){
        throw 12;
    }


    data -> Convert();

}

bool Position::playable(){
    return false;
}

Piece* Position::getContent(){
    return data;
}