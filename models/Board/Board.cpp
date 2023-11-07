#include "./Board.hpp"
#include <iostream>
#include "../PlayablePosition/PlayablePosition.hpp"

Board::Board(){

    for(int i=0;i < 8;i++){
        std::vector<Position *> row;

        for(int j=0; j < 8; j++)
            row.push_back(nullptr);

        this->data.push_back(row);
    }


}

Board::Board(const Board &b){
    this -> data = b.data;
}


void Board::Draw(){

    std::cout <<"-----------------\n";

    for(int i=0;i<8;i++){

        std::cout << "|";
        for(int j=0;j<8;j++){
            data[i][j] -> Draw();
            std::cout << "|";
        }

        std::cout <<"\n-----------------\n";
    }
}




std::vector<Position *>& Board::operator[](int index){

    return data[index];

}

/*
-----------------
| | | | | | | | |

*/