#ifndef BOARD_H
#define BOARD_H
#include "../Coordinate/Coordinate.hpp"
#include "../Interfaces/IPosition.hpp"
#include <array>
#include <vector>

class Board
{
private:

    std::array<std::array<IPosition*,10>,10> map;


    void generateBorders();

public:

    Board();

    Board(std::array<std::string , 8> rawData);
    void Draw();
    void Refresh(Color);

    std::vector<Coordinate> getAvailableCoordinate();


    std::array<IPosition*,10>& operator[](int);


};

#endif