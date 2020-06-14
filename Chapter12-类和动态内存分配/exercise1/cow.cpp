// cow.cpp -- cow class methods
#include <iostream>
#include <cstring> // string.h for some
#include "cow.h"
using namespace std;

// default constructor
Cow::Cow()
{
    std::strcpy(name, "Meatlf");
    hobby = new char[20]; // pointer to string
    std::strcpy(hobby, "study");
    weight = 150;
}

// constructor
Cow::Cow(const char *nm, const char *ho, double wt)
{
    std::strcpy(name, nm);
    hobby = new char[20]; // pointer to string
    std::strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow &c)
{
    std::strcpy(name, c.name);
    hobby = new char[20]; // pointer to string
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

// destructor
Cow::~Cow()
{
    delete[] hobby;
}

Cow &Cow::operator=(const Cow &c)
{
    std::strcpy(name, c.name);
    hobby = new char[20]; // pointer to string
    std::strcpy(hobby, c.hobby);
    weight = c.weight;
}

std::ostream &operator<<(std::ostream &os, const Cow &c)
{
    os << "cow's name: " << c.name << endl;
    os << "cow's hobby: " << c.hobby << endl;
    os << "cow's weight: " << c.weight << endl;
}

// display all cow data
void Cow::ShowCow() const
{
    cout << "cow's name: " << name << endl;
    cout << "cow's hobby: " << hobby << endl;
    cout << "cow's weight: " << weight << endl
         << endl;
}
