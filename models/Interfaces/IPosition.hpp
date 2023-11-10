#ifndef IPOSITION_H
#define IPOSITION_H
#include "../Piece/Piece.hpp"
#include "../Coordinate/Coordinate.hpp"

class IPosition
{
public:

    virtual bool playable() = 0;
    virtual bool isEmpty() = 0;
    virtual void ConvertPiece() = 0;
    virtual Piece* getContent() = 0;
    virtual void Draw() = 0;  
    virtual Coordinate getCoordinate() = 0;

};



#endif