// cow.h -- flawed string class definition
#include <iostream>
#ifndef COW_H_
#define COW_H_
class Cow
{
private:
    char name[20];
    char *hobby; // pointer to string
    double weight;

public:
    Cow();                                          // default constructor
    Cow(const char *nm, const char *ho, double wt); // constructor
    Cow(const Cow &c);
    ~Cow(); // destructor
    Cow &operator=(const Cow &c);
    friend std::ostream &operator<<(std::ostream &os, const Cow &c);
    void ShowCow() const; // display all cow data
};
#endif
