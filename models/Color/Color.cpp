#include "./Color.hpp"


Color& operator!(Color& c)
{
    if (c==Color::Black)
        c = Color::White;
    else
        c = Color::Black;
}

std::ostream& operator<<(std::ostream& os,Color& c)
{
    if(c==Color::Black)
        os << "B";
    else
        os << "W";

    return os;
}