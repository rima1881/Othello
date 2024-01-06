#include "./Board.hpp"
#include <iostream>
#include "../EmptyPosition/EmptyPosition.hpp"
#include "../FilledPosition/FilledPosition.hpp"
#include "../Border/Border.hpp"

//Center has to be added
Board::Board(){

    generateBorders();    

    for(int i = 1;i < 9;i++)
        for(int j = 1 ;j < 9;j++)
            map[i][j] = new EmptyPosition(i,j);

}



std::function<Location(Location loc)> Board::movingStrategy[8] = { 
        //0
        [] (Location loc) {
            loc.i++;
            return loc;
        },
        //45
        [] (Location loc) {
            loc.i++;
            loc.j++;
            return loc;
        },
        //90
        [] (Location loc) {
            loc.j++;
            return loc;
        },
        //135
        [] (Location loc) {
            loc.i--;
            loc.j++;
            return loc;
        },
        //180
        [] (Location loc) {
            loc.i--;
            return loc;
        },
        //225
        [] (Location loc) {
            loc.i--;
            loc.j--;
            return loc;
        },
        //270
        [] (Location loc) {
            loc.j--;
            return loc;
        },
        //315
        [] (Location loc) {
            loc.i++;
            loc.j--;
            return loc;
        }

};



void Board::generateBorders(){

    for(int i=0;i < 10;i++){
        map[0][i] = new Border(0,i);
        map[9][i] = new Border(9,i);
        map[i][0] = new Border(i,0);
        map[i][9] = new Border(i,9);
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


void Board::Put(EmptyPosition* pos,bool Color){

    if(!(pos -> Playable()))
        throw 12;

    int i = pos -> getI();
    int j = pos -> getJ();

    convertPositions(pos);

    delete pos;

    map[i][j] = new FilledPosition(i,j,Color);

}



std::vector<EmptyPosition*> Board::getAvailableCoordinate(){

    std::vector<EmptyPosition*> res;

    for(int i=1;i<9;i++)
        for(int j=1;j<9;j++)
            if(map[i][j]->Playable())
                res.push_back((EmptyPosition*) map[i][j]);

    return res;
}


int Board::Count(bool color){

    Content c = color ? Content::White : Content::Black;

    int res = 0;

    for(int i = 0; i < 9 ; i++)
        for(int j=0 ; j < 9; j++)
            if(map[i][j] -> getContent() == c)
                res++;

    return res;
}

void Board::Refresh(bool color) {

    for(int i = 1; i < 9; i++)
        for(int j = 1; j < 9; j++)
            if(map[i][j] -> getContent() == Content::Empty)
                    checkPosition((EmptyPosition*)map[i][j]);


}



void Board::checkPositions(EmptyPosition* pos , bool color){

    bool avaibleDirections[8];

    Location initialLoction = pos->getLocation();

    for(int i=0;i<8;i++)
        avaibleDirections[i] = checkDirection(movingStrategy[i], initialLoction, color);


    pos -> setAvailableDirs(avaibleDirections);


}




/*
-----------------
| | | | | | | | |

*/