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
    if(data == nullptr)
        std::cout << Piece::EmptySymbol;
    else if(data -> IsBlack())
        std::cout << Piece::BlackSymbol;
    else
        std::cout << Piece::WhiteSymbol;

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