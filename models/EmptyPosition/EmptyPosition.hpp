#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Position/Position.hpp"
#include <array>
class EmptyPosition : public Position
{
private:

    bool availableDirs[8];

public:

    EmptyPosition(int i,int j);
    void setAvailableDirs(bool[8]);

    bool Playable();
    void Draw();

};

#endif