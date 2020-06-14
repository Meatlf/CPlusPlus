// exercise1.cpp  --
#include <iostream>
#include <string>
#include "cow.h"
using namespace std;

int main()
{
    Cow cow0;
    cout << cow0 << endl;
    Cow cow1("ttz", "play", 152);
    cout << cow1 << endl;
    Cow cow2 = cow1;
    cout << cow2 << endl;
    Cow cow3(cow2);
    cout << cow3 << endl;

    cow0.ShowCow();
    cow1.ShowCow();
    cow2.ShowCow();
    cow3.ShowCow();
    return 0;
}
