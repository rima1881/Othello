#ifndef PSQUARE_H
#define PSQUARE_H
#include "../Position/Position.hpp"
#include <array>
class EmptyPosition : public Position
{
private:

    std::array<bool,8> availableDirs;

public:

    EmptyPosition(int i,int j);
    void setAvailableDirs(std::array<bool,8>);
    std::array<bool,8> getAvailableDirs();

    bool Playable();
    void Draw();

};

#endif