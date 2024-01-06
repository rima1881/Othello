#include "./Position.hpp"


Position::Position(int i,int j,Content con) : content(con) { 

    this -> loc.i = i;
    this -> loc.j = j;

}


Content Position::getContent(){
    return this -> content;
}

int Position::getI(){
    return loc.i;
}

int Position::getJ(){
    return loc.j;
}

Location Position::getLocation(){
    return loc;
}