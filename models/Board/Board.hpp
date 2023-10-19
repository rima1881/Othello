#ifndef BOARD_H
#define BOARD_H
#include "../interfaces/ISquare.hpp"


class Board
{
private:
    ISquare*** map;
public:
    Board(int state);
    Board(const Board &b);
    void Draw();
    ISquare*** getMap();
};

#endif