#include "golf.h"

golf::golf()
{
    char *name = new char[25];
    int hc;
    cout << "Please input name: ";
    cin.getline(name, 50);
    cout << "Please input handicap:";
    cin >> hc;
    strcpy(fullname_, name);
    handicap_ = hc;
    cin.get();
}

golf::golf(const char *name, int hc)
{
    strcpy(fullname_, name);
    handicap_ = hc;
}

void golf::setgolf(const char *name, int hc)
{
    golf(name, hc);
}

void golf::setgolf()
{
    golf();
}

void golf::handicap(int hc)
{
    handicap_ = hc;
}

void golf::showgolf()
{
    cout << "Fullname:  " << fullname_ << " Handicap: " << handicap_ << endl;
}

golf::~golf()
{
}
