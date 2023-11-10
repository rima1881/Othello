
#include "./Board.hpp"
#include "../FilledPosition/FilledPosition.hpp"

void Board::convert0(int i,int j,Color c){

    i++;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        i++;
    }
    

}


void Board::convert45(int i,int j,Color c){

    i++;
    j++;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        i++;
        j++;
    }
    
}

void Board::convert90(int i,int j,Color c){

    j++;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        j++;
    }
    

}

void Board::convert135(int i,int j,Color c){

    i--;
    j++;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        i--;
        j++;
    }
    

}


void Board::convert180(int i,int j,Color c){

    i--;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        i--;
    }
    
}

void Board::convert225(int i,int j,Color c){

    i--;
    j--;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        i--;
        j--;
    }
    

}


void Board::convert270(int i,int j,Color c){

    j--;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        j--;
    }
    

}

void Board::convert315(int i,int j,Color c){

    i++;
    j--;

    while (true)
    {

        if(map[i][j] -> getContent() -> getColor() == c)
            break;


        delete(map[i][j]);
        map[i][j] = new FilledPosition(new Piece(c),Coordinate(i,j));


        i++;
        j--;
    }
    

}
