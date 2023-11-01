#include "./Position.hpp"
#include <iostream>
#include "../Error/Error.hpp"

Piece* Position::getContent(){
    return content;
}
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
    if(this -> content == nullptr)
        std::cout << " ";
    else
        content -> Draw();
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