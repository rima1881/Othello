#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Piece/Piece.hpp"
#include "../Position/Position.hpp"

class PlayablePosition : public Position
{
private:
    Piece* content;
public:
    PlayablePosition();
    PlayablePosition(Piece* content);

    virtual bool playable();
    virtual void setContent(Piece*);
};

#endif