#include "bank_count.h"
#include <iostream>

int main()
{
    BankCount user0("Micoral","123456");
    user0.display();

    double deposit = 3.4;
    user0.deposit(deposit);
    user0.display();

    double draw = 2.9;
    user0.draw(draw);
    user0.display();
}