#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Piece/Piece.hpp"
#include "../Position/Position.hpp"

class PlayablePosition : public Square
{
private:
    Piece* content;
public:
    PlayablePosition();
    PlayablePosition(Piece* content);
    PlayablePosition(const PlayablePosition &PlayableSquare);

    //ISQUARE
    virtual void Draw();
    virtual bool playable();
    virtual Piece* getContent();
    virtual void setContent(Piece*);
    virtual int getX();
    virtual int getY();
};

#endif