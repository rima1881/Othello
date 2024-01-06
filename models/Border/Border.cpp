#include "Border.hpp"

Border::Border(int i,int j) : Position(i,j,Content::Empty) {


}


void Border::Draw() {

    if(i == 0 && j != 9)
        std::cout << j;
    else if(j == 0 && i != 9)
        std::cout << i;

}

bool Border::Playable(){
    return false;
}