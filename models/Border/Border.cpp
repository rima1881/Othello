#include "Border.hpp"

Border::Border(int i,int j) : Position(i,j,Content::Empty) {


}


void Border::Draw() {

    if(loc.i == 0 && loc.j != 9)
        std::cout << loc.j;
    else if(loc.j == 0 && loc.i != 9)
        std::cout << loc.i;

}

bool Border::Playable(){
    return false;
}