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
                       const string & count, double deposit, double draw){
                           name_ = name;
                           count_ = count;
                           deposit_ = deposit;
                           draw_ = draw;
                       }

void BankCount::display (){

                       }
             
