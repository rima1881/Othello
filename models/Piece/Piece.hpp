#ifndef PIECE_H
#define PIECE_H

class Piece
{
private:
    bool Black;
public:

    static char BlackSymbol;
    static char WhiteSymbol;
    static char EmptySymbol;

    Piece(bool Black);
    bool IsBlack();
    void Convert();

};

#endif