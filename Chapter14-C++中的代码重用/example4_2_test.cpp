// 功能：testing the template Calc class
#include <iostream>
#include "calc.h"
using std::cin;
using std::cout;

int main()
{
    Calc<unsigned long> st; // create an empty Calc
    st.show();
    cout << st.add() << std::endl;
    cout << st.sub() << std::endl;
    return 0;
}
