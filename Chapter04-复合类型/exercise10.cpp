// exercise10.cpp -- array variations
#include <iostream>
#include <array> // C++0x
int main()
{
    using namespace std;
    const int times = 3;
    // C++0x -- create and initialize array object
    array<double, times> a;

    for (int i = 0; i < times; i++)
    {
        cout << "请输入第" << i + 1 << "次跑40米的时间：";
        cin >> a[i];
        cout << endl;
    }

    double total_times = 0;
    for (int i = 0; i < times; i++)
    {
        cout << "第" << i + 1 << "次跑40米的时间：" << a[i] << endl;
        total_times += a[i];
    }
    cout << "跑" << times << "次的平均时间：" << total_times / times << endl;

    //  cin.get();
    return 0;
}