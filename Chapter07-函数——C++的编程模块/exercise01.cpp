// exercise1.cpp --
// 功能：求2个数的调和平均数
// 说明：除了实现该题目的功能之外，还使用到后续章节里的函数模板和异常
#include <iostream>
#include <cmath>

template <typename T>
void test_harmonic_mean(T x, T y);

template <typename T>
inline T harmonic_mean(T a, T b);

int main()
{
    using namespace std;
    auto x = 0.0f;
    auto y = 0.0f;
    test_harmonic_mean(x, y);
    // cin.get();
    return 0;
}

template <typename T>
void test_harmonic_mean(T x, T y)
{
    using namespace std;
    cout << "输入两个数：";
    while (cin >> x >> y)
    {
        auto z = 0.0;
        try
        {
            z = harmonic_mean(x, y);
        }
        catch (const char *s)
        {
            std::cerr << s << '\n';
            cout << "请保证输入的每个数都不等于0！" << endl;
            cout << "请再次输入调和平均数：";
            continue;
        }
        cout << "调和平均数为： " << z << endl;
        cout << "输入两个数：";
    }
}

template <typename T>
inline T harmonic_mean(T x, T y)
{
    if (fabs(x + y) < 0.0001)
        throw "对于调和平均数的计算不允许参数x = -y";
    return 2.0 * x * y / (x + y);
}