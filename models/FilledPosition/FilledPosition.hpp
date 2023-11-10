#ifndef FILLEDPOSION_H
#define FILLEDPOSTION_H
#include "../Piece/Piece.hpp"
#include "../Interfaces/IPosition.hpp"
#include "../Coordinate/Coordinate.hpp"

class FilledPosition : public IPosition
{
private:
    Piece* piece;
    Coordinate co;
public:

    FilledPosition(Piece*,Coordinate);
    bool playable();
    bool isEmpty();
    void ConvertPiece();
    Piece* getContent();
    void Draw();  
    Coordinate getCoordinate();
    ~FilledPosition();


};

#endif