// cd.h -- 
#ifndef CD_H_
#define CD_H_
#include <string>
using std::string;
// simple base class
class Cd
{
private:
    char performers[50];
    char label[20];
    int selections ;
    double playtime;
public:
    Cd (char * s1, char * s2, int n, double x);
    Cd (const Cd & d);
    Cd ();
    virtual ~Cd();
    virtual void Report() const;
    Cd & operator=(const Cd & d);
};

class Classic : public Cd
{
private:
    char name_[4];
public:
    Classic(char* name, char* s1, char* s2,  int n, double x);
    Classic(char* name, const Cd & cd);
    Classic();
};
#endif
