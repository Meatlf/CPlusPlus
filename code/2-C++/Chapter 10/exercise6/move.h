// tabtenn0.h -- a table-tennis base class
#ifndef MOVE_H_
#define MOVE_H_
#include<iostream>
#include<cstring>

using namespace std;

class Move
{
private:
    /* data */
    double x;
    double y;
public:
    Move(double a=0,double b=0);
    void showmove() const;
    Move add(const Move & m);
    void reset(double a=0, double b=0);

    ~Move();
};

#endif
