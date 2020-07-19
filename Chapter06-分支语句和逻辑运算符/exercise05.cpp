// exercise05.cpp -- using if else if else
// 参考资料:

#include <iostream>
const int Fave = 27;

int main()
{
    using namespace std;
    int n;

    cout << "请输入您的工资：";

    int tax = 0.0;

    // 当用户输入负数或非数字时，循环将结束
    while (cin >> n && n > 0)
    {
        if (n < 5000)
        {
            cout << "收入低于5000 tvarps，所得税为： 0.0" << endl;
        }
        else if (5000 < n && n < 15000)
        {
            cout << "收入介于5001～15000 tvarps，所得税为： " << 0.1 * (n - 5000) << endl;
        }
        else if (15000 < n && n < 35000)
        {
            cout << "收入介于15001～35000 tvarps，所得税为： " << 0.15 * n - 1250 << endl;
        }
        else
        {
            cout << "收入高于35000 tvarps，所得税为： " << 0.2 * n - 3000 << endl;
        }
        cout << "请输入您的工资：";
    };
    // cin.get();
    // cin.get();
    return 0;
}