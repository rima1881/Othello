#include "./Board.hpp"
#include <iostream>
#include "../PlayableSquare/PlayableSquare.hpp"

Board::Board(int state){
    this -> map = new ISquare**[8];

    for(int i=0;i<8;i++) {
        this -> map[i] = new ISquare*[8];
        for(int j = 0;j < 8 ; j++) {
            this -> map[i][j] = new PlayableSquare();
        }
    }

}

Board::Board(const Board &b){
    this -> map = b.map;
}

ISquare*** Board::getMap(){
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