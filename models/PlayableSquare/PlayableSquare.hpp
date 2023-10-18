#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Piece/Piece.hpp"

class PlayableSquare
{
private:
    /* data */
public:
    PlayableSquare(/* args */);


    //ISQUARE
    virtual bool playable();
    virtual Piece* getContent();
    virtual char setContent();
    virtual int getX();
    virtual int getY();
};

#endif