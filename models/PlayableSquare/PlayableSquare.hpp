#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Piece/Piece.hpp"

class PlayableSquare
{
private:
    Piece* content;
public:
    PlayableSquare();
    PlayableSquare(Piece* content);
    PlayableSquare(const PlayableSquare &PlayableSquare);

    //ISQUARE
    virtual bool playable();
    virtual Piece* getContent();
    virtual void setContent(Piece*);
    virtual int getX();
    virtual int getY();
};

#endif