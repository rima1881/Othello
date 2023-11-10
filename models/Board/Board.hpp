#ifndef BOARD_H
#define BOARD_H
#include "../Coordinate/Coordinate.hpp"
#include "../Interfaces/IPosition.hpp"
#include <vector>

class Board
{
private:

    IPosition* map[9][9];

public:
    Board();
    void Draw();

};

#endif