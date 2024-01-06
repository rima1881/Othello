#ifndef BOARD_H
#define BOARD_H
#include "../Position/Position.hpp"
#include "../EmptyPosition/EmptyPosition.hpp"
#include <array>
#include <vector>
#include <functional>
#include <algorithm>



class Board
{
private:

    std::array<std::array<Position*,10>,10> map;

    static std::function<Location(Location loc)> movingStrategy[8];

    void checkPositions(EmptyPosition*,bool color);
    void convertPositions(EmptyPosition*,bool color);

    bool checkDirection(std::function<Location(Location loc)> direction , Location initialLocation , bool color);
    void convertDirection(std::function<Location(Location loc)> direction , Location initialLocation , bool color);

    void generateBorders();

public:

    Board();

    void Draw();
    void Put(EmptyPosition*,bool);
    void Refresh(bool);
    int Count(bool);
    std::vector<EmptyPosition*> getAvailableCoordinate();


    std::array<Position*,10>& operator[](int);

};

#endif