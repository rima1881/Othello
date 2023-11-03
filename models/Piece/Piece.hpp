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

    //it is declared as static because there are some null pieces and instead of multiple if's or having draw 
    static void Draw(Piece* piece);
};

#endif