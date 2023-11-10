#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
private:
    int i;
    int j;

public:

    void setI(int);
    void setJ(int);

    int getI();
    int getJ();

    Coordinate(int,int);
};


#endif