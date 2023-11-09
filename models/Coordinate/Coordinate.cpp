#include "./Coordinate.hpp"

Coordinate::Coordinate(int i, int j){
    this -> i = i;
    this -> j = j;
}

int Coordinate::getI(){
    return this -> i;
}

int Coordinate::getJ(){
    return this -> j;
}

void Coordinate::setI(int i){
    this -> i = i;
}

void Coordinate::setJ(int j){
    this -> j = j;
}

Coordinate::Coordinate(){
    
}