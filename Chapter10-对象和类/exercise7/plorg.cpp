#include <cstring>
#include "plorg.h"

Plorg::Plorg()
{
    strcpy(_name, "Plorga");
    _CI = 50;
}

Plorg::Plorg(char *c, int CI)
{
    strcpy(_name, c);
    _CI = CI;
}

Plorg::~Plorg()
{
}

void Plorg::showPlorg() const
{
    cout << "Name: " << _name << endl
         << "CI: " << _CI << endl;
}

void Plorg::setCI(int CI)
{
    _CI = CI;
}