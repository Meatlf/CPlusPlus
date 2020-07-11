// Golf.cpp --
// 功能：
// 说明：使用到了后续章节里的模板类
#include <iostream>
#include <cstring>

const int N = 10;

template <typename T>
void test_golf(T x);

template <typename T>
class Golf
{
private:
    T _x[N];
    int _n;

public:
    Golf();
    ~Golf();
    void set_input();
    void display();
    T average();
};

template <typename T>
Golf<T>::Golf()
{
    memset(_x, 0, N * sizeof(T));
    _n = N;
}

template <typename T>
Golf<T>::~Golf()
{
}

template <typename T>
void Golf<T>::set_input()
{
    using namespace std;

    cout << "输入10个数据(输入'q'则提前结束)：";

    T number = 0;
    for (int i = 0; i < _n; i++)
    {
        cin >> number;
        if (number == 'q')
        {
            _x[i] = '\0';
            break;
        }
        _x[i] = number;
    }
}

template <typename T>
void Golf<T>::display()
{
    using namespace std;

    cout << "显示输入的数据：";
    for (int i = 0; i < _n, (i < _n && _x[i] != '\0'); i++)
    {
        cout << _x[i] << " ";
    }
    cout << endl;
}

template <typename T>
T Golf<T>::average()
{
    using namespace std;
    T sum = 0;
    int i;
    for (i = 0; (i < _n && _x[i] != '\0'); i++)
    {
        sum += _x[i];
    }
    return sum / i;
}

// template <typename T>
// T test_golf(T x);

// template <typename T>
// void set_input(T x[], int n);

// template <typename T>
// void display(const T x[], int n);

// template <typename T>
// T average(const T x[], int n);

int main()
{
    using namespace std;

    // auto number = 0.0f;
    // cout << "输入10个数据(输入'q'则提前结束)：";
    // auto sum = test_golf(number);
    // cout << "输入的数据之和为："
    //      << sum << endl;

    Golf<double> golf;
    golf.set_input();
    golf.display();
    cout << "输入的数据平均值为：" << golf.average() << endl;
    // cin.get();
    return 0;
}

template <typename T>
T test_golf(T x)
{
    using namespace std;
    T sum = 0;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        if (x == 'q')
            break;
        sum += x;
    }
    return sum;
}
