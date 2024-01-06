#ifndef BORDER_H
#define BORDER_H
#include "../Position/Position.hpp"

class Border : public Position
{
public:
    Border(int i,int j);

    void Draw();
    bool Playable();
};

#endif