// exercise1.cpp
// 说明：相关技术有：内联函数，引用变量，const，默认参数，函数重载
#include <iostream>
#include <string>

using namespace std;

template <typename T>
inline void show_str(const string &str, T n = 3);

int main()
{
    double x = 3.0;

    string str = "abc";
    show_str(str, 5);
    // cin.get();
    return 0;
}

template <typename T>
void show_str(const string &str, T n)
{
    cout << str << endl;
}