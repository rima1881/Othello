#include "./Board.hpp"
#include <iostream>
#include "../PlayablePosition/PlayablePosition.hpp"

Board::Board(int state){
    this -> map = new Position**[8];

    for(int i=0;i<8;i++) {
        this -> map[i] = new Position*[8];
        for(int j = 0;j < 8 ; j++) {
            this -> map[i][j] = new Position();
        }
    }

}

Board::Board(const Board &b){
    this -> map = b.map;
}

Position*** Board::getMap(){
    return this -> map;
}

void Board::Draw(){

    std::cout <<"-----------------\n";

    for(int i=0;i<8;i++){

        std::cout << "|";
        for(int j=0;j<8;j++){
            map[i][j] -> Draw();
            std::cout << "|";
        }

        std::cout <<"\n-----------------\n";
    }
}

/*
-----------------
| | | | | | | | |

*/