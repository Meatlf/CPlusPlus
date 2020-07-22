// tabtenn0.h -- a table-tennis base class
#ifndef GOLF_H_
#define GOLF_H_
#include <iostream>
#include <cstring>

using namespace std;

struct golf
{
    string fullname;
    int handicap;
};

void setgolf(golf &g, const string name, int hc);

void setgolf(golf &g);

void handicap(golf &g, int hc);

void showgolf(const golf &g);
#endif
