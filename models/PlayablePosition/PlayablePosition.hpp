#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Interfaces/IPosition.hpp"
class PlayablePosition : public IPosition
{
public:

    PlayablePosition();
    bool playable();
    bool isEmpty();
    void ConvertPiece();
    Piece* getContent();
    void Draw();  
};

#endif