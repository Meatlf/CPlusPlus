// 功能：从标准输入读入几个整数，存入向量容器，输出它们的相反数
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    const int N = 5;
    vector<int> s(N); // 容器
    for (int i = 0; i < N; i++)
        cin >> s[i];
    // 算法，   迭代器，                                              函数对象
    transform(s.begin(), s.end(), ostream_iterator<int>(cout, " "), negate<int>());
    cout << endl;
    return 0;
}