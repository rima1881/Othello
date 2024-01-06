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


    delete map[4][4];
    map[4][4] = new FilledPosition(5,5,true);
    delete map[4][5];
    map[4][5] = new FilledPosition(5,6,false);
    delete map[5][4];
    map[5][4] = new FilledPosition(6,5,false);
    delete map[5][5];
    map[5][5] = new FilledPosition(6,6,true);

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

    convertPositions(pos,Color);

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
                    checkPositions((EmptyPosition*)map[i][j],color);


}



void Board::checkPositions(EmptyPosition* pos , bool color){

    std::array<bool,8> avaibleDirections = { false , false , false , false , false , false, false, false};
    Location initialLoction = pos->getLocation();


    for(int i=0;i<8;i++)
        avaibleDirections[i] = checkDirection(movingStrategy[i], initialLoction, color);

    pos -> setAvailableDirs(avaibleDirections);


}



bool Board::checkDirection(std::function<Location(Location loc)> direction , Location initialLocation , bool color){

    Location next = direction(initialLocation);
    Content c = color ? Content::White : Content::Black;

    if(map[next.i][next.j]->getContent() == Content::Empty || map[next.i][next.j]->getContent() == c)
        return false;

    next = direction(next);
    while (map[next.i][next.j]-> getContent() != Content::Empty)
    {
        if(map[next.i][next.j] -> getContent() == c)
            return true;

        next = direction(next);
    }

    return false;

}


void Board::convertPositions( EmptyPosition* pos , bool color){

    std::array<bool,8> avDirs = pos -> getAvailableDirs();

    for(int i=0;i<8;i++)
        if(avDirs[i])
            convertDirection(movingStrategy[i],pos -> getLocation(),color);

}

void Board::convertDirection(std::function<Location(Location loc)> direction , Location initialLocation , bool color){

    Content c = color ? Content::White : Content::Black;

    Location next = direction(initialLocation);

    while(map[next.i][next.j] -> getContent() != c){

        ((FilledPosition*) map[next.i][next.j]) -> Convert();

        next = direction(next);

    }
 

}