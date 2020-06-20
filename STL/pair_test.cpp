// 参考资料：
// [1] [Pair in C++ Standard Template Library (STL)](https://www.geeksforgeeks.org/pair-in-cpp-stl/)
#include <iostream>
#include <utility>
#include <string>

// 一般初始化
void pair_test1()
{
    std::pair<int, char> PAIR1;
    PAIR1.first = 100;
    PAIR1.second = 'G';
    std::cout << PAIR1.first << " ";
    std::cout << PAIR1.second << std::endl;
}

// 一般初始化
void pair_test2()
{
    std::pair<int, char> g1;
    std::pair<int, char> g2(1, 'a');
    std::pair<int, int> g3(1, 10);
    // 以下语句会报错
    // std::pair<int, int> g2(g3);
}

// 一般初始化
void pair_test3()
{
    std::pair<std::string, double> PAIR2("GeeksForGeeks", 1.23);
    std::cout << PAIR2.first << " ";
    std::cout << PAIR2.second << std::endl;
}

// 默认初始化
void pair_test4()
{
    std::pair<std::string, double> PAIR3;
    std::cout << PAIR3.first << " ";
    std::cout << PAIR3.second << std::endl;
}

// std::make_pair()的使用
void pair_test5()
{
    std::pair<int, char> PAIR1;
    std::pair<std::string, double> PAIR2("GeeksForGeeks", 1.23);
    std::pair<std::string, double> PAIR3;

    PAIR1.first = 100;
    PAIR1.second = 'G';

    PAIR3 = std::make_pair("GeeksForGeeks is Best", 4.56);

    std::cout << PAIR1.first << " ";
    std::cout << PAIR1.second << std::endl;

    std::cout << PAIR2.first << " ";
    std::cout << PAIR2.second << std::endl;

    std::cout << PAIR3.first << " ";
    std::cout << PAIR3.second << std::endl;
}

// 关于pair的重载运算符
void pair_test6()
{
    std::pair<int, int> pair1 = std::make_pair(1, 12);
    std::pair<int, int> pair2 = std::make_pair(9, 12);

    std::cout << (pair1 == pair2) << std::endl;
    std::cout << (pair1 != pair2) << std::endl;
    std::cout << (pair1 >= pair2) << std::endl;
    std::cout << (pair1 <= pair2) << std::endl;
    std::cout << (pair1 > pair2) << std::endl;
    std::cout << (pair1 < pair2) << std::endl;
}

// 基于pair的交换
void pair_test7()
{
    std::pair<char, int> pair1 = std::make_pair('A', 1);
    std::pair<char, int> pair2 = std::make_pair('B', 2);

    std::cout << "Before swapping:\n ";
    std::cout << "Contents of pair1 = " << pair1.first << " " << pair1.second;
    std::cout << "Contents of pair2 = " << pair2.first << " " << pair2.second;

    pair1.swap(pair2);

    std::cout << "\nAfter swapping:\n";
    std::cout << "Contents of pair1 = " << pair1.first << " " << pair1.second << std::endl;
    std::cout << "Contents of pair2 = " << pair2.first << " " << pair2.second << std::endl;
}

int main()
{
    pair_test1();
    pair_test2();
    pair_test3();
    pair_test4();
    pair_test5();
    pair_test6();
    pair_test7();
    return 0;
}