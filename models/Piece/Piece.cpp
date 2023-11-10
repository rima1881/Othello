#include "./Piece.hpp"
#include <iostream>


Piece::Piece(Color color):color(color){ }

void Piece::Convert(){
    switch (color)
    {
    case Color::Black:
        color = Color::White;
        break;
    
    case Color::White:
        color = Color::Black;
        break;
    }
}


std::ostream& operator<<(std::ostream& os, const Piece& p){

    switch (p.color)
    {
    case Color::Black:
        os << "B";
        return os;
    case Color::White:
        os << "W";
        return os;
    }

    return os;

}