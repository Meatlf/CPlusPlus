// use_stuc.cpp -- using a composite class
// compile with studentc.cpp
#include <iostream>
#include <string>
#include <valarray>
#include "teacher.h"
using std::cin;
using std::cout;
using std::endl;

int main()
{
    const std::string s = "Meatlf";
    const std::valarray<int> a(3, 9);
    Teacher t(s, a);
    t.Show();
    return 0;
}