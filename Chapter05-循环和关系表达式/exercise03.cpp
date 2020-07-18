// exercise03.cpp --
#include <iostream>

using namespace std;

const int ArSize = 100; // example of external declaration
int main()
{
    int n;
    cout << "请输入一个整数（输入0时，程序结束）： ";
    cin >> n;
    int sum = 0;
    while (n != 0)
    {
        sum += n;
        cout << "输入的累加和为： " << sum<<endl;

        cout << "请输入一个整数： ";
        cin >> n;
    }

    // std::cin.get();
    return 0;
}