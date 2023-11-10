#include "./Board.hpp"
#include <iostream>
#include "../PlayablePosition/PlayablePosition.hpp"
#include "../UnPlayablePosition/UnPlayablePosition.hpp"
#include "../FilledPosition/FilledPosition.hpp"
#include "../Border/Border.hpp"

Board::Board(){

    generateBorders();    


    for(int i = 1;i < 9;i++)
        for(int j = 1 ;j < 9;j++)
            map[i][j] = new UnPlayablePosition(Coordinate(i,j));

}

Board::Board(std::array<std::string,8> rawData){

    generateBorders();

    for(int i=0;i < 8;i++){

        //curropted data :(
        if(rawData[i].size() != 8)
            throw 8;

        for(int j=0;j < 8;j++)
            switch (rawData[i][j])
            {
            case '.':
                map[i + 1][j + 1] = new UnPlayablePosition(Coordinate(i+1,j+1));
                break;
            case 'B':
                map[i + 1][j + 1] = new FilledPosition(new Piece(Color::Black),Coordinate(i+1,j+1));
                break;
            case 'W':
                map[i + 1][j + 1] = new FilledPosition(new Piece(Color::White),Coordinate(i+1,j+1));
                break;
            default:
                throw 8;
            }

    }

}

void Board::generateBorders(){

    for(int i=0;i < 10;i++){
        map[0][i] = new Border(Coordinate(0,i));
        map[9][i] = new Border(Coordinate(9,i));
        map[i][0] = new Border(Coordinate(i,0));
        map[i][9] = new Border(Coordinate(i,9));
    }

}
void Board::Draw(){


    for(int i=0;i<10;i++){

        for(int j=0;j<10;j++){
            std::cout << " ";
            map[i][j] -> Draw();
        }

        std::cout << "\n";
    }
}


std::array<IPosition*,10>& Board::operator[](int i){

    return map[i];
}

std::vector<Coordinate> Board::getAvailableCoordinate(){

    std::vector<Coordinate> res;

    for(int i=1;i<9;i++)
        for(int j=1;j<9;j++)
            if(map[i][j]->playable())
                res.push_back(map[i][j]->getCoordinate());

    return res;
}


void Board::Refresh(Color refreshFor) {


    resetPlayables();


    for(int i = 1; i < 9; i++){

        for(int j = 1; j < 9; j++){
            
            if(map[i][j] -> isEmpty()){
                std::array<bool,8> availableDirs = check_Position(i,j,refreshFor);
                if(availableDirs[0] || availableDirs[1] || availableDirs[2] || availableDirs[3] || availableDirs[4] || availableDirs[5] || availableDirs[6] || availableDirs[7]){

                    delete(map[i][j]);
                    map[i][j] = new PlayablePosition(Coordinate(i,j), availableDirs);

                }
            }
        }
    }


}

void Board::resetPlayables(){

    for(int i=1;i<9;i++)
        for(int j=1;j < 9;j++)
            if(map[i][j] -> isEmpty()){
                delete(map[i][j]);
                map[i][j] = new UnPlayablePosition(Coordinate(i,j));
            }

}

void Board::Put(Coordinate co,Color color){

    int i = co.getI() , j = co.getJ();

    if(!map[i][j]->playable())
        throw 12;

    std::array<bool,8> dirs = static_cast<PlayablePosition *> (map[i][j]) -> getConvertableDirections();

    if(dirs[0])
        convert0(i,j, color);

    if(dirs[1])
        convert45(i,j, color);

    if(dirs[2])
        convert90(i,j, color);

    if(dirs[3])
        convert135(i,j, color);

    if(dirs[4])
        convert180(i,j, color);

    if(dirs[5])
        convert225(i,j, color);

    if(dirs[6])
        convert270(i,j, color);

    if(dirs[7])
        convert315(i,j, color);

    delete(map[i][j]);
    map[i][j] = new FilledPosition(new Piece(color),co);


}

/*
-----------------
| | | | | | | | |

*/