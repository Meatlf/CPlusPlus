// exercise1.cpp  --
#include <iostream>
#include <string>
#include "string2.h"
using namespace std;

int main()
{
    String s1(" and I am a C++ student.");
    String s2 = "Please enter your name: ";
    String s3;
    cout << s2;
    cin >> s3;
    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    return 0;
}
