// exercise6.cpp
// 说明：
#include <iostream>
#include <algorithm>
#include <cstring>

template <class T>
T maxn(T a[], int n) // #1
{
    T Max = a[0];
    for (int i = 1; i < n; i++)
        Max = std::max(Max, a[i]);
    return Max;
}

char *maxn(char *c[], int n) // #1
{
    char *Max = c[0];
    for (int i = 1; i < n; i++)
        Max = std::strlen(Max) > std::strlen(c[i]) ? Max : c[i];
    return Max;
}

int main()
{
    using namespace std;

    int a[6] = {1, 2, 6, 4, 5, 4};
    int n = 6;
    cout << maxn(a, n) << endl;

    double b[4] = {3.2, 2.0, 6.3, 4.5};
    n = 5;
    cout << maxn(b, 4) << endl;

    char *c[5] = {"sdfds", "sfdfd", "dff", "dfsdfdsgghhsdf", "d"};
    n = 5;
    cout << maxn(c, 5) << endl;

    // cin.get();
    return 0;
}