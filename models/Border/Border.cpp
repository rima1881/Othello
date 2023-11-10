#include "Border.hpp"

Border::Border(Coordinate data) : UnPlayablePosition(data) { }


void Border::Draw() {
    std::cout << "#";
}