#include "./Error.hpp"

std::string Error::errorMessages[2] = { "Game attended to put in a position that wasn't suppose to put. please restart the game" , "Error!!!:settings file was not found.\n The game will run with basic functionallites. if you want the full game you can download db folder from github and\nplace it in the same directory of your executable" } ; 


Error::Error(int code){
    this -> code = code;
}

std::string Error::getMsg(){
    return Error::errorMessages[code];
}

int Error::getCode(){
    return code;
}