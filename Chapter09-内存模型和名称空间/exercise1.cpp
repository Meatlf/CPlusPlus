// 参考资料：
// [1] "C++ Primer Plus" "4.2.5 混合输入字符串和数字"
#include "golf.h"

const int n = 3;

int main()
{
    golf ann[n];
    string s1;
    int handicap;

    for (int i = 0; i < n; i++)
    {
        cout << "请输入Fullname：";
        getline(cin, s1);
        cout << "请输入Handicap：";
        cin >> handicap;
        cin.get();
        setgolf(ann[i], s1, handicap);
    }

    for (int i = 0; i < n; i++)
    {
        cout << "第" << i << "个人的信息为：";
        showgolf(ann[i]);
    }
    return 0;
}