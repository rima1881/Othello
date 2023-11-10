#include "./UnPlayablePosition.hpp"


UnPlayablePosition::UnPlayablePosition(Coordinate data) : co(data)
{ 

}

//***********************************************
void UnPlayablePosition::ConvertPiece(){
    throw 12;
}


bool UnPlayablePosition::playable(){
    return false;
}
bool UnPlayablePosition::isEmpty(){
    return true;
}


Piece* UnPlayablePosition::getContent(){
    return nullptr;
}

void UnPlayablePosition::Draw(){
    std::cout << "*";
}

Coordinate UnPlayablePosition::getCoordinate(){
    return this -> co;
}