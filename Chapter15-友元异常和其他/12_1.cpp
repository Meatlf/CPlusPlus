// error3.cpp -- using an exception
#include <iostream>
using namespace std;

int divide(int x, int y)
{
    if (y == 0)
        // 可以将"throw x"理解为调用“函数”"catch(int e)"
        throw x; // 抛出异常
    return x / y;
}

int main()
{
    try
    // try保护段
    {
        cout << "5/2 = " << divide(5, 2) << endl;
        cout << "8/0 = " << divide(8, 0) << endl;
        cout << "7/1 = " << divide(7, 1) << endl;
    }
    catch (int e)
    // 异常处理程序
    {
        cout << e << " is divided by zero!" << endl;
    }
    cout << "Bye!\n";
    return 0;
}