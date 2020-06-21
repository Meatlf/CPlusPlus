// wine.h -- defining a Student class using containment
#ifndef WINEC_H_
#define WINEC_H_

#include <iostream>
#include <string>
#include <valarray>
#include "pair.h"

class Wine
{
private:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;
    std::string label;
    int years;
    PairArray data;

public:
    Wine() : label("Null label"), years(0), data(ArrayInt(0), ArrayInt(0)){};
    Wine(const char *l, int y, const int yr[], const int bot[]) : label(l), years(y), data(ArrayInt(yr, y), ArrayInt(bot, y)){};
    Wine(const char *l, int y) : label(l), years(y), data(ArrayInt(y), ArrayInt(y)){};
    void GetBottles();
    void Show() const;
    const std::string &Label() const { return label; };
    int sum();
};
#endif
