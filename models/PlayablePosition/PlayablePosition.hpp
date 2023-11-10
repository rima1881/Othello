#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Interfaces/IPosition.hpp"
#include <array>
class PlayablePosition : public IPosition
{
private:

    Coordinate co;
    std::array<bool,8> ConvertableDirections;

public:

    PlayablePosition(Coordinate,std::array<bool,8>);
    bool playable();
    bool isEmpty();
    void ConvertPiece();
    void Draw();  

    void setConvertableDirections(std::array<bool,8>);

    std::array<bool,8> getConvertableDirections();
    Coordinate getCoordinate();
    Piece* getContent();


};

#endif