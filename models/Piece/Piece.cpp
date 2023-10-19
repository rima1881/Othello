#include "./Piece.hpp"
#include <iostream>

Piece::Piece(bool Black){
    this -> Black = Black;
}
void Piece::Convert(){
    this -> Black = !Black;
}

bool Piece::IsBlack(){
    return this -> Black;
}

void Piece::Draw(){
    
    if(Black)
        std::cout << "B";
    else
        std::cout << "W";

}