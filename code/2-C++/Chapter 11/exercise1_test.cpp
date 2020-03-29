// useWalker1.cpp -- using the second draft of the Walker class
// compile useWalker1.cpp and myWalker1.cpp together
#include <iostream>
#include "walker.h"

int main()
{
    using std::cout;
    using std::endl;
    Walker planning;
    Walker coding(2, 40);
    Walker fixing(5, 55);
    Walker total;

    planning.Show();
    cout << endl;
 
    cout << "coding Walker = ";
    coding.Show();
    cout << endl;
    
    cout << "fixing Walker = ";
    fixing.Show();
    cout << endl;

    total = coding + fixing;
    // operator notation
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    Walker morefixing(3, 28);
    cout << "more fixing Walker = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    // function notation
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
    // std::cin.get();
    return 0;
}
