// tabtenn0.h -- a table-tennis base class
#ifndef GOLF_H_
#define GOLF_H_
#include<iostream>
#include<cstring>

using namespace std;

const int Len = 40;

class golf
{
private:
    /* data */
    char fullname_[Len];
    int handicap_;
public:
    golf();
    golf(const char * name, int hc);

    void handicap(int hc);

    void showgolf(int hc);

    void showgolf();

    ~golf();
};

#endif
