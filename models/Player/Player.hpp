#ifndef PLAYER_H
#define PLAYER_H

#include <string>
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
    void takeTurn();
    
};

#endif