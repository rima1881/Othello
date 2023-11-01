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

    virtual bool playable();
    virtual void setContent(Piece*);

    Piece* getContent();
    int getX();
    int getY();
    void Draw();
    void ConvertPiece();
    
};



#endif