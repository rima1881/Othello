#include "./Piece.hpp"
#include <iostream>

//I was too lazy to customize this one so be my guest if you want to
char Piece::EmptySymbol = ' ';
    //these two will be changed in game load data function
char Piece::BlackSymbol = ' ';
char Piece::WhiteSymbol = ' ';


Piece::Piece(bool Black){
    this -> Black = Black;
}
void Piece::Convert(){
    this -> Black = !Black;
}

bool Piece::IsBlack(){
    return this -> Black;
}