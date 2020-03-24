// tabtenn0.h -- a table-tennis base class
#ifndef BANKCOUNT_H_
#define BANKCOUNT_H_
#include<string>
#include<iostream>

using namespace std;

class BankCount
{
private:
    string name_;
    string count_;
    double deposit_;
public:
    BankCount (const string & name, const string & count);
    void display();
    void deposit(double deposit);
    void draw(double draw);
    ~BankCount();
};
#endif
