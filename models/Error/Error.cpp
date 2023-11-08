#include "./Error.hpp"

std::string Error::errorMessages[2] = { "Game attended to put in a position that wasn't suppose to put. please restart the game" , "" } ; 


Error::Error(int code){
    this -> code =code;
}

std::string Error::getMsg(){
    return Error::errorMessages[code];
}

int Error::getCode(){
    return code;
}