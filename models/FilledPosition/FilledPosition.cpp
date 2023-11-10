#include "./FilledPosition.hpp"


FilledPosition::FilledPosition(Piece* p,Coordinate data) : co(data){
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
    std::cout << *piece;
}

Coordinate FilledPosition::getCoordinate(){
    return co;
}
FilledPosition::~FilledPosition(){
    delete(piece);
}