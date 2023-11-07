#ifndef BOARD_H
#define BOARD_H
#include "../Position/Position.hpp"
#include <vector>

class Board
{
private:

    std::vector<std::vector<Position*>> data;
    bool checkPosion(int i,int j,bool isBlack);

    bool check_d0(int i,int j,bool isBlack);
    bool check_d45(int i,int j,bool isBlack);
    bool check_d90(int i,int j,bool isBlack);
    bool check_d135(int i,int j,bool isBlack);
    bool check_d180(int i,int j,bool isBlack);
    bool check_d235(int i,int j,bool isBlack);
    bool check_d270(int i,int j,bool isBlack);
    bool check_d315(int i,int j,bool isBlack);




public:
    Board();
    Board(const Board &b);
    void Draw();
    void ModifyBoard(bool);
    std::vector<Position *>& operator[](int);

};

#endif