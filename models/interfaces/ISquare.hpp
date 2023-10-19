#ifndef ISQUARE_H
#define ISQUARE_H
#include "../Piece/Piece.hpp"

class ISquare
{
public:
    virtual bool playable() = 0;
    virtual Piece* getContent() = 0;
    virtual void setContent(Piece*) = 0;
    virtual int getX() = 0;
    virtual int getY() = 0;
    virtual void Draw() = 0;
    virtual void ConvertPiece() = 0;
};

#endif