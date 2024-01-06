#ifndef IPOSITION_H
#define IPOSITION_H
#include "../Content/Content.hpp"

struct Location
{
    int i;
    int j;
};



class Position
{
    protected:

    Location loc;
    Content content;

    public:

    Position(int i,int j,Content con);

    int getI();
    int getJ();
    Location getLocation();
    Content getContent();


    //pure virtual
    virtual bool Playable() = 0;
    virtual void Draw() = 0;  

};



#endif