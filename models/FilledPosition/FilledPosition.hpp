#ifndef FILLEDPOSION_H
#define FILLEDPOSTION_H
#include "../Piece/Piece.hpp"
#include "../Interfaces/IPosition.hpp"

class FilledPosition : public IPosition
{
private:
    Piece* piece;
public:

    FilledPosition(Piece*);


    bool playable();
    bool isEmpty();
    void ConvertPiece();
    Piece* getContent();
    void Draw();  


    ~FilledPosition();

};

#endif