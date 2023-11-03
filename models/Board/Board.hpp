#ifndef BOARD_H
#define BOARD_H
#include "../Position/Position.hpp"


class Board
{
private:
    Position*** map;
public:
    Board(int state);
    Board(const Board &b);
    void Draw();
    Position*** getMap();
};

#endif