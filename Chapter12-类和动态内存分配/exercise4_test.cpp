// exercise3_test.cpp -- using the Stock class
// compile with exercise3_test.cpp
#include <iostream>
#include "stack.h"

const int STKS = 4;
int main()
{
    Stack st0;
    Item a = 3, b = 4, c = 5;
    st0.push(a);
    st0.push(b);
    st0.push(c);
    std::cout << st0.isfull() << std::endl;
    std::cout << st0.isempty() << std::endl;
    Item d = 0;
    std::cout << st0.pop(d) << " " << d << std::endl;

    Stack st1 = st0;
    std::cout << st1.isfull() << std::endl;
    std::cout << st1.isempty() << std::endl;
    std::cout << st1.pop(d) << " " << d << std::endl;

    return 0;
}
