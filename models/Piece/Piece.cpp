#include "./Piece.hpp"
#include <iostream>


Piece::Piece(Color color){
    this -> color = color;
}
void Piece::Convert(){
    this -> color = !color;
}

void Piece::Draw(){
    std::cout << color;
}