#include "Border.hpp"

Border::Border(Coordinate data) : UnPlayablePosition(data) { }


void Border::Draw() {

    if(co.getI() == 0 && co.getJ() != 9)
        std::cout << co.getJ();
    else if(co.getJ() == 0 && co.getI() != 9)
        std::cout << co.getI();

}