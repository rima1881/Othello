#include "./Board.hpp"
#include <iostream>
#include "../PlayablePosition/PlayablePosition.hpp"
#include "../UnPlayablePosition/UnPlayablePosition.hpp"
#include "../Border/Border.hpp"

Board::Board(){

    //border
    for(int i=0;i < 10;i++){
        map[0][i] = new Border();
        map[9][i] = new Border();
        map[i][0] = new Border();
        map[i][9] = new Border();
    }


    for(int i = 1;i < 9;i++)
        for(int j = 1 ;j < 9;j++)
            map[i][j] = new UnPlayablePosition();

}


void Board::Draw(){


    for(int i=0;i<10;i++){

        for(int j=0;j<10;j++){
            map[i][j] -> Draw();
        }

        std::cout << "\n";
    }
}




/*
-----------------
| | | | | | | | |

*/