#ifndef FILLEDPOSION_H
#define FILLEDPOSTION_H
#include "../Position/Position.hpp"

class FilledPosition : public Position
{
public:

    FilledPosition(int i,int j,bool color);

    //IPosition
    void Draw();
    bool Playable();
    void Convert();

};

#endif