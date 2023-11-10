#include "./FilledPosition.hpp"


FilledPosition::FilledPosition(Piece* p){
    this -> piece = p;
}

bool FilledPosition::playable(){
    return false;
}
bool FilledPosition::isEmpty(){
    return false;
}
void FilledPosition::ConvertPiece(){
    this -> piece -> Convert();
}

Piece* FilledPosition::getContent(){
    return this -> piece;
}
void FilledPosition::Draw(){
    this -> Draw();
}