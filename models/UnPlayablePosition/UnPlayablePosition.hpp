#ifndef UNPLAYABLEPOSTION_H
#define UNPLAYABLEPOSTION_H
#include "../Interfaces/IPosition.hpp"

class UnPlayablePosition : public IPosition
{
protected:
    Coordinate co;
public:

    UnPlayablePosition(Coordinate);

    bool playable();
    bool isEmpty();
    void ConvertPiece();
    Piece* getContent();
    Coordinate getCoordinate();
    virtual void Draw();  
};

#endif