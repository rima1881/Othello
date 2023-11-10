#include "./UnPlayablePosition.hpp"


UnPlayablePosition::UnPlayablePosition(){ }

//***********************************************
void UnPlayablePosition::ConvertPiece(){
    throw 12;
}


bool UnPlayablePosition::playable(){
    return false;
}
bool UnPlayablePosition::isEmpty(){
    return false;
}


Piece* UnPlayablePosition::getContent(){
    return nullptr;
}

void UnPlayablePosition::Draw(){
    std::cout << " ";
}  