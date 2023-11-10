#ifndef BORDER_H
#define BORDER_H
#include "../UnPlayablePosition/UnPlayablePosition.hpp"

class Border : public UnPlayablePosition
{
public:
    Border(Coordinate);
    void Draw();
};

#endif