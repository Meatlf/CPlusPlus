#include"golf.h"

void setgolf(golf & g, const char * name, int hc)
{
    strcpy(g.fullname, name);
    g.handicap = hc;
}

void setgolf(golf & g)
{
    char* name = new char [25];
    int hc;
    cout << "Please input name: ";
    cin >> name;
    cout << "Please input handicap:";
    cin >> hc;
    strcpy(g.fullname, name);
    g.handicap = hc;
}