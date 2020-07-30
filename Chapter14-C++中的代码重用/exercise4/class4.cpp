// class4.cpp -- class methods
#include "class4.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
// Person methods

// must implement virtual destructor, even if pure
Person::~Person() {}

void Person::Show() const
{
    cout << "First Name: " << _firstname << "\n";
    cout << "Last Name: " << _lastname << "\n";
}

// Gunslinger methods
void Gunslinger::Show() const
{
    cout << "Category: waiter\n";
    Person::Show();
    cout << "Nick Number: " << nickNumber << "\n";
}

double Gunslinger::Draw() const
{
    return 32.1;
}

// PokerPlayer methods
int PokerPlayer::Draw()
{
    return 1;
}

void PokerPlayer::Show() const
{
    cout << "Category: singer\n";
    Person::Show();
}

float BadDude::Gdraw()
{
    return 2.0;
}

int BadDude::Cdraw()
{
    return 1;
}