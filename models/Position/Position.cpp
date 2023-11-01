#include "./Position.hpp"
#include <iostream>
#include "../Error/Error.hpp"

Piece* Square::getContent(){
    return content;
}
void Square::setContent(Piece* content){
    this -> content = content; 
}
int Square::getX(){
    return this -> x;
}
int Square::getY(){
    return this -> y;
}
void Square::Draw(){
    if(this -> content == nullptr)
        std::cout << " ";
    else
        content -> Draw();
}

void Square::ConvertPiece(){

    if(content == nullptr){
        throw 12;
    }


    content -> Convert();

}

