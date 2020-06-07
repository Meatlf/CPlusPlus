// tabtenn0.h -- a table-tennis base class
#ifndef GOLF_H_
#define GOLF_H_
#include<iostream>
#include<cstring>

using namespace std;

const int Len = 40;
struct golf
{
    char fullname[Len];
    int handicap;
};

void setgolf(golf & g, const char * name, int hc);

void setgolf(golf & g);

void handicap(golf & g, int hc);

void showgolf(golf & g, int hc);

void showgolf(const golf & g);
#endif
