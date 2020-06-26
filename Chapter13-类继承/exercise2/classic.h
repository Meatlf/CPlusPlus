// cd.h --
#ifndef CLASSIC_H_
#define CLASSIC_H_
#include <iostream>
#include <string>
using std::string;
using namespace std;

// simple base class
class Cd
{
private:
    char *performers;
    char *label;
    int selections;
    double playtime;

public:
    Cd(const char *s1, const char *s2, int n, double x);
    Cd(const Cd &d);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd &operator=(const Cd &d);
};

class Classic : public Cd
{
private:
    char *works;

public:
    Classic(const char *w, const char *s1, const char *s2, int n, double x);
    Classic(const Classic &c);
    Classic();
    virtual ~Classic();
    virtual void Report() const;
    Classic &operator=(const Classic &c);
};
#endif
