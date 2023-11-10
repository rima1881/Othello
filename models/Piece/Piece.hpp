#ifndef PIECE_H
#define PIECE_H
#include "../Color/Color.hpp"

class Piece
{
private:
    Color color;
public:

    Piece(Color Black);
    Piece(Piece &p);
    void Draw();
    void Convert();

};

#endif