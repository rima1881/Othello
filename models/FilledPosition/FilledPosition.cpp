#include "./FilledPosition.hpp"


FilledPosition::FilledPosition(int i,int j,bool color) : Position(i,j,color ? Content::White : Content::Black){ }

bool FilledPosition::Playable(){
    return false;
}


void FilledPosition::Convert(){

    if(this -> content == Content::Black)
        this -> content = Content::White;
    else
        this -> content = Content::Black;

}

void FilledPosition::Draw(){

    if(this -> content == Content::Black)
        std::cout << "B";
    else
        std::cout << "W";

}
