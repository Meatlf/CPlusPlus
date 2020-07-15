// exercise5.cpp
// 说明：
#include <iostream>
#include <algorithm>

template <class T>
T max5(T a[]) // #1
{
    T Max = a[0];
    for (int i = 1; i < 5; i++)
        Max = std::max(Max, a[i]);
    return Max;
}

int main()
{
    using namespace std;

    int a[5] = {1, 2, 6, 4, 5};
    cout << max5(a) << endl;

    double b[5] = {3.2, 2.0, 6.3, 4.5, 5.9};
    cout << max5(b) << endl;

    // cin.get();
    return 0;
}