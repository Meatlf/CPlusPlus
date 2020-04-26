#include <iostream>
#include <vector>

void test_begin()
{
    std::vector<int> myvector;
    for (int i = 1; i <= 5; i++)
        myvector.push_back(i);

    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

// vector assign
// 功能:设置vector中的内容.
// ## 参考资料
// [std::vector::assign](http://www.cplusplus.com/reference/vector/vector/assign/)
void test_assign()
{
    std::vector<int> first;
    std::vector<int> second;
    std::vector<int> third;

    // 用法1
    first.assign(7, 100); // 7 ints with a value of 100

    for (size_t i = 0; i < first.size(); i++)
        std::cout << ' ' << first[i];
    std::cout << std::endl;

    // 用法2
    std::vector<int>::iterator it;
    it = first.begin() + 1;

    second.assign(it, first.end() - 1); // the 5 central values of first

    for (size_t i = 0; i < second.size(); i++)
        std::cout << ' ' << second[i];
    std::cout << std::endl;

    // 用法3
    int myints[] = {1776, 7, 4};
    third.assign(myints, myints + 3); // assigning from array.

    for (size_t i = 0; i < third.size(); i++)
        std::cout << ' ' << third[i];
    std::cout << std::endl;

    std::cout << "Size of first: " << int(first.size()) << '\n';
    std::cout << "Size of second: " << int(second.size()) << '\n';
    std::cout << "Size of third: " << int(third.size()) << '\n';
}

// clearing vectors
// ## 功能: clear用于清空vector.
// ## 参考资料
// [std::vector::clear](http://www.cplusplus.com/reference/vector/vector/clear/)
void test_clear()
{
    std::vector<int> myvector;
    myvector.push_back(100);
    myvector.push_back(200);
    myvector.push_back(300);

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    myvector.clear();
    myvector.push_back(1101);
    myvector.push_back(2202);

    std::cout << "myvector contains:";
    for (unsigned int i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';
}

// vector insert
// 功能:使用insert在vector中插入新元素.
// ## 参考资料
// [std::vector::insert](http://www.cplusplus.com/reference/vector/vector/insert/)
void test_insert()
{
    std::vector<int> myvector(3, 100);
    std::vector<int>::iterator it;

    it = myvector.begin();
    it = myvector.insert(it, 200);

    myvector.insert(it, 2, 300);

    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    // "it" no longer valid, get a new one:
    it = myvector.begin();

    std::vector<int> anothervector(2, 400);
    myvector.insert(it + 2, anothervector.begin(), anothervector.end());
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << std::endl;

    int myarray[] = {501, 502, 503};
    myvector.insert(myvector.begin(), myarray, myarray + 3);

    std::cout << "myvector contains:";
    for (it = myvector.begin(); it < myvector.end(); it++)
        std::cout << ' ' << *it;
    std::cout << '\n';
}

// swap 交换2个vector
void test_swap()
{
    std::vector<int> foo(3, 100); // three ints with a value of 100
    std::vector<int> bar(5, 200); // five ints with a value of 200

    foo.swap(bar);

    std::cout << "foo contains:";
    for (unsigned i = 0; i < foo.size(); i++)
        std::cout << ' ' << foo[i];
    std::cout << std::endl;

    std::cout << "bar contains:";
    for (unsigned i = 0; i < bar.size(); i++)
        std::cout << ' ' << bar[i];
    std::cout << std::endl;
}

int main()
{
    // test_begin();
    // test_assign();
    // test_clear();
    // test_insert();
    test_swap();
    return 0;
}