#ifndef BOARDMODIFIER_H
#define BOARDMODIFIER_H

#include "../Board/Board.hpp"


class BoardModifier
{
private:
    Board* board;
public:
    BoardModifier(Board* b);

    bool check_d0(int i,int j,bool isBlack);
    bool check_d45(int i,int j,bool isBlack);
    bool check_d90(int i,int j,bool isBlack);
    bool check_d135(int i,int j,bool isBlack);
    bool check_d180(int i,int j,bool isBlack);
    bool check_d225(int i,int j,bool isBlack);
    bool check_d270(int i,int j,bool isBlack);
    bool check_d315(int i,int j,bool isBlack);

};

#endif