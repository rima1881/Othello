#ifndef PIECE_H
#define PIECE_H

class Piece
{
private:
    bool Black;
public:
    Piece(bool Black);
    bool IsBlack();
    void Convert();
    void Draw();
};

#endif