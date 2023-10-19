#ifndef USQUARE_H
#define USQUARE_H
#include "../Square/Square.hpp"



class UnPlayableSquare : public Square
{
private:
    Piece* content;
public:

    UnPlayableSquare(/* args */);
    virtual bool playable();

};

#endif