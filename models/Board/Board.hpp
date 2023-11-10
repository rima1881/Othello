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

    bool check_d0(int i,int j,Color c);
    bool check_d45(int i,int j,Color c);
    bool check_d90(int i,int j,Color c);
    bool check_d135(int i,int j,Color c);
    bool check_d180(int i,int j,Color c);
    bool check_d225(int i,int j,Color c);
    bool check_d270(int i,int j,Color c);
    bool check_d315(int i,int j,Color c);


    void convert0(int i,int j,Color c);
    void convert45(int i,int j,Color c);
    void convert90(int i,int j,Color c);
    void convert135(int i,int j,Color c);
    void convert180(int i,int j,Color c);
    void convert225(int i,int j,Color c);
    void convert270(int i,int j,Color c);
    void convert315(int i,int j,Color c);



    std::array<bool,8> check_Position(int i,int j,Color c);

    void generateBorders();

    void resetPlayables();

public:

    Board();
    Board(std::array<std::string , 8> rawData);

    void Draw();
    void Refresh(Color);
    void Put(Coordinate,Color);
    int Count(Color);
    std::vector<Coordinate> getAvailableCoordinate();



    std::array<IPosition*,10>& operator[](int);


};

#endif