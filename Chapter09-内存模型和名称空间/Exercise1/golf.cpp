#include <iostream>
#include "golf.h"

using namespace std;

void setgolf(golf &g, const string name, int hc)
{
    g.fullname = name;
    g.handicap = hc;
}

void setgolf(golf &g)
{
    string name;
    int hc;
    cout << "Please input name: ";
    cin >> name;
    cout << "Please input handicap:";
    cin >> hc;
    g.fullname = name;
    g.handicap = hc;
}

void handicap(golf &g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf &g)
{
    cout << "Fullname: " << g.fullname << "    Handicap: " << g.handicap << endl;
}