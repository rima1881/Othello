#ifndef SQUARE_H
#define SQUARE_H
#include "../Piece/Piece.hpp"

class Position
{
private:

    Piece* content;
    int x;
    int y;

public:

    Position();
    Position(Piece* content);

    virtual bool playable();
    virtual void setContent(Piece*);
    virtual void ConvertPiece();

    Piece* getContent();
    int getX();
    int getY();
    void Draw();
    
};



#endif