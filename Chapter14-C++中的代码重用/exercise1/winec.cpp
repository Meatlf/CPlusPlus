// studentc.cpp -- Student class using containment
#include "winec.h"
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

//public methods
void Wine::GetBottles()
{
    cout << "Enter year: ";
    cin >> information[0][0];
    cout << year;
}

int Wine::Label()
{
    return 0;
}

int Wine::sum()
{
    return 0;
}

// private method

// friends

// use string version of operator>>()

// use string friend getline(ostream &, const string &)

// use string version of operator<<()
