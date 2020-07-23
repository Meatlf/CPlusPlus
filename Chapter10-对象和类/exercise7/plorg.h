// tabtenn0.h -- a table-tennis base class
#ifndef Plorg_H_
#define Plorg_H_
#include <iostream>
#include <cstring>

using namespace std;

class Plorg
{
private:
    /* data */
    char _name[19];
    int _CI;

public:
    Plorg();
    Plorg(char *c, int CI);
    void showPlorg() const;
    void setCI(int CI);

    ~Plorg();
};

#endif
