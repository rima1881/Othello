#ifndef UNPLAYABLEPOSTION_H
#define UNPLAYABLEPOSTION_H
#include "../Interfaces/IPosition.hpp"

class UnPlayablePosition : public IPosition
{
public:

    UnPlayablePosition();

    bool playable();
    bool isEmpty();
    void ConvertPiece();
    Piece* getContent();
    virtual void Draw();  
};

#endif