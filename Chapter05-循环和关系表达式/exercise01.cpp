// exercise01.cpp --
#include <iostream>
using namespace std;

const int ArSize = 16; // example of external declaration
int main()
{
    long long factorials[ArSize];
    int left, right;
    cout << "请输入左整数： ";
    cin >> left;
    cout << "请输入右整数： ";
    cin >> right;

    int sum = 0;
    if (left > right)
        return 0;
    else
    {
        for (int i = left; i <= right; i++)
            sum += i;
        cout << "左整数和右整数之间的整数和为： " << sum << endl;
    }
    // std::cin.get();
    return 0;
}
