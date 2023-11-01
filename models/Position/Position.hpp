#ifndef SQUARE_H
#define SQUARE_H
#include "../interfaces/ISquare.hpp"
#include "../Piece/Piece.hpp"

class Square : public ISquare
{
private:

    Piece* content;
    int x;
    int y;

public:

    virtual Piece* getContent();
    virtual void setContent(Piece*);
    virtual int getX();
    virtual int getY();
    virtual void Draw();
    virtual void ConvertPiece();
    
};



#endif