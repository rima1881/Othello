#ifndef SQUARE_H
#define SQUARE_H
#include "../Piece/Piece.hpp"

class Position
{
private:

    Piece* data;
    int x;
    int y;

public:

    Position();
    Position(Piece* content);

    virtual bool playable();
    virtual void setContent(Piece*);
    virtual void ConvertPiece();

    int getX();
    int getY();
    Piece* getContent();
    void Draw();
    
};



#endif