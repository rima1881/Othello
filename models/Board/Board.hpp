#ifndef BOARD_H
#define BOARD_H
#include "../Position/Position.hpp"
#include <vector>

class Board
{
private:
    std::vector<std::vector<Position*>> data;

public:
    Board();
    Board(const Board &b);
    void Draw();
    std::vector<Position *>& operator[](int);

};

#endif