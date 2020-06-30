// calc.h -- a Calc template
#ifndef CALC_H_
#define CALC_H_
#include <iostream>

template <class Type>
class Calc
{
private:
    enum
    {
        MAX = 10
    };               // constant specific to class
    Type items[MAX]; // holds Calc items
    int val;         // index for top Calc item
public:
    Calc();
    Type add();
    Type sub();
    void show();
};

template <class Type>
Calc<Type>::Calc()
{
    val = 0;
}

template <class Type>
Type Calc<Type>::add()
{
    return val++;
}

template <class Type>
Type Calc<Type>::sub()
{
    return val--;
}

template <class Type>
void Calc<Type>::show()
{
    std::cout << val << std::endl;
}

#endif
