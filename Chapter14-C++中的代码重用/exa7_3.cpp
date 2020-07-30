// 说明：当派生类和基类具有同名的方法时，派生类对象将使用派生类的方法，还是基类的方法？
// 参考资料：[虚函数](https://next.xuetangx.com/learn/THU08091000248/THU08091000248/1510503/video/1246288)
#include <iostream>
using namespace std;

// 基类Base1
class Base1
{
private:
    /* data */
public:
    void display() const
    {
        cout << "Base1::display()" << endl;
    }
};

// 派生类Base2
class Base2 : public Base1
{
private:
    /* data */
public:
    void display() const { cout << "Base2::display()" << endl; }
};

// 派生类Derived
class Derived : public Base2
{
public:
    void display() const { cout << "Derived display()" << endl; }
};

void fun(Base1*ptr)
{
    ptr->display();
}

int main()
{
    Base1 base1;
    Base2 base2;
    Derived derived;

    fun(&base1);
    fun(&base2);
    fun(&derived);

    return 0;
}