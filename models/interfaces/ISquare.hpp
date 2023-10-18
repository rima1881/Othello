#ifndef ISQUARE_H
#define ISQUARE_H
#include "../Piece/Piece.hpp"

class ISquare
{
public:
    virtual bool playable() = 0;
    virtual Piece* getContent() = 0;
    virtual char setContent() = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
};

#endif