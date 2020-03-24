//tabtenn0.cpp -- simple base-class methods
#include "bank_count.h"
#include <iostream>

// class BankCount
// {
// private:
//     string name;
//     string count;
//     double deposit;
//     double draw;
// public:
//     BankCount (const string & name,
//                        const string & count, double deposit, double draw);
//     void display();
//     void deposit(double deposit);
//     double draw();
//     ~BankCount();
// };

BankCount::BankCount (const string & name,
                       const string & count)
{
    name_ = name;
    count_ = count;
    deposit_ = 0;
}

void BankCount::display ()
{
    cout << "User name: " << name_ << ", Count name: " << count_ << ", Deposit: " << deposit_ << endl;
}

void BankCount::deposit(double deposit)
{
    if(deposit > 0)
        deposit_ += deposit;
}

void BankCount::draw(double draw)
{
    if(deposit_ > draw)
        deposit_ -= draw;
}

BankCount::~BankCount()
{

}          
