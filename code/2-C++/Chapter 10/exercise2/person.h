// tabtenn0.h -- a table-tennis base class
#ifndef BANKCOUNT_H_
#define BANKCOUNT_H_
#include<iostream>
#include<string>
#include<cstring>

using namespace std;

class Person
{
private:
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
    string name_;
public:
    Person();
    Person (const string & ln, const char * fn = "Heyyou");
    void Show() const;
    void Forma1Show() const;
    ~Person();
};
#endif
