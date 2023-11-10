#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Interfaces/IPosition.hpp"
class PlayablePosition : public IPosition
{
private:
    Coordinate co;
public:

    PlayablePosition(Coordinate);
    bool playable();
    bool isEmpty();
    void ConvertPiece();
    Piece* getContent();
    Coordinate getCoordinate();
    void Draw();  
};

#endif