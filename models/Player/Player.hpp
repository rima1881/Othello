#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "../EmptyPosition/EmptyPosition.hpp"

class Player
{
private:

    std::string name;
    bool color;
    int score;

public:

    Player(std::string name,bool color);
    

    EmptyPosition* takeTurn(std::vector<EmptyPosition*> availablePositions);


    //setters
    void setScore(int);

    //getters
    bool getColor();
    int getScore();
    std::string getName();

    
};

#endif