// wine.h -- defining a Student class using containment
#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <string>
#include <valarray>

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    T1 &first();
    T2 &second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

template <class T1, class T2>
T1 &Pair<T1, T2>::first()
{
    return a;
}
template <class T1, class T2>
T2 &Pair<T1, T2>::second()
{
    return b;
}

class Wine
{
private:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;
    std::string label;
    int year;
    PairArray information;

public:
    Wine() : label("Null label"), information(){};
    Wine(const char *l, int y, const int yr[], const int bot[]) : label(l), information({1, 2, 4, 5}, {4, 4, 5, 9}){};
    Wine(const char *l, int y) : label(l){
        information= {{4,4,4,4}, {4,4,4,4}};
    };
    void GetBottles();
    void Show();
    int Label();
    int sum();
};
#endif
