#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "../Coordinate/Coordinate.hpp"
class Player
{
private:

    std::string name;
    bool isBlack;

public:

    Player(std::string name,bool is_black);
    std::string Color();
    bool IsBlack();
    std::string getName();
    Coordinate takeTurn(std::vector<Coordinate> availablePositions);
    
};

#endif