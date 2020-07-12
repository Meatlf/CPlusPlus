// exercise05.cpp -- using recursion
// 说明：该程序主要是为了熟悉如何写递归代码，安全性很低
#include <iostream>
int factorial(int n);

int main()
{
    int n;

    std::cout << "请输入一个数(输入q则终止): ";
    while (std::cin >> n && n != 'q')
    {
        std::cout << "输入的数为： " << n << "，其阶乘为： " << factorial(n) << std::endl; // call the recursive function
        std::cout << "请输入一个数(输入q则终止): ";
    }
    // std::cin.get();
    return 0;
}

int factorial(int n)
{
    if (n > 0)
        return n * factorial(n - 1); // function calls itself
    else
    {
        return 1;
    }
}
