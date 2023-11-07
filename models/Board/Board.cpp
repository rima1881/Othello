#include "./Board.hpp"
#include <iostream>
#include "../PlayablePosition/PlayablePosition.hpp"

bool Board::checkPosion(int i,int j,bool isBlack){

    return check_d0(i,j,isBlack) || check_d45(i,j,isBlack) || check_d90(i,j,isBlack) || check_d135(i,j,isBlack) || check_d180(i,j,isBlack) || check_d235(i,j,isBlack) || check_d270(i,j,isBlack) || check_d315(i,j,isBlack);
}

bool Board::check_d0(int i,int j,bool isBlack){

    if(i == 7)
        return false;

    i++;
    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i++;

    while(i < 8){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i++;
    }

    return false;

}

bool Board::check_d45(int i,int j,bool isBlack){

    if(i == 7 || j == 7)
        return false;

    i++;
    j++;
    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i++;
    j++;

    while(i < 8 && j < 8){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i++;
        j++;
    }

    return false;

}


bool Board::check_d90(int i,int j,bool isBlack){

    if(j == 7)
        return false;

    j++;
    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    j++;

    while(j < 8){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        j++;
    }

    return false;

}

bool Board::check_d135(int i,int j,bool isBlack){

    if(i == 0 || j == 7)
        return false;

    i--;
    j++;
    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i--;
    j++;

    while(j < 8 && i > -1){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i++;
    }

    return false;

}

bool Board::check_d180(int i,int j,bool isBlack){

    if(i == 0)
        return false;

    i--;
    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i--;

    while(i > -1){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i--;
    }

    return false;

}

bool Board::check_d235(int i,int j,bool isBlack){

    if( i==0 || j==0)
        return false;

    i--;
    j--;

    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i--;
    j--;

    while(i > -1 && j > -1){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i--;
        j--;
    }

    return false;

}


bool Board::check_d270(int i,int j,bool isBlack){

    if(j ==0)
        return false;

    j--;
    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    j--;

    while(j > -1){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        j--;
    }

    return false;

}

bool Board::check_d315(int i,int j,bool isBlack){

    if(i == 7 || j==0)
        return false;

    i++;
    j--;

    if( data[i][j] -> getContent() == nullptr || data[i][j] -> getContent() -> IsBlack() == isBlack )
        return false;

    i++;
    j--;

    while(i < 8 && j > -1){

        if(data[i][j] -> getContent() == nullptr )
            break;
        
        if(data[i][j] -> getContent() -> IsBlack() == isBlack)
            return true;

        i++;
        j--;
    }

    return false;

}



void Board::ModifyBoard(bool isBlack){


    for(int i=0; i < 8 ; i++){
        for(int j=0; j < 8; j++){
            if(data[i][j] -> getContent() != nullptr)  
                continue;
            else{
                if(Board::checkPosion(i,j,isBlack))
                    data[i][j] = new PlayablePosition();
            }
        }
    }
}

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