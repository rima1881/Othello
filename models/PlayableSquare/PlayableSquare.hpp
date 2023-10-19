#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Piece/Piece.hpp"
#include "../interfaces/ISquare.hpp"

class PlayableSquare : public ISquare
{
private:
    Piece* content;
public:
    PlayableSquare();
    PlayableSquare(Piece* content);
    PlayableSquare(const PlayableSquare &PlayableSquare);

    //ISQUARE
    virtual void Draw();
    virtual bool playable();
    virtual Piece* getContent();
    virtual void setContent(Piece*);
    virtual int getX();
    virtual int getY();
};

#endif