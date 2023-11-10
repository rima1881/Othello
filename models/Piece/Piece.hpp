#ifndef PIECE_H
#define PIECE_H
#include "../Color/Color.hpp"
#include <iostream>

class Piece
{
private:
    Color color;
public:

    Piece(Color Black);
    Piece(Piece &p);
    void Convert();

    friend std::ostream& operator<<(std::ostream& os, const Piece& p);


};

#endif