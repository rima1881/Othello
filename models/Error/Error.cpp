#include "./Error.hpp"

Error::Error(std::string msg){
    this ->msg = msg;
}

std::string Error::getMsg(){
    return this -> msg;
}