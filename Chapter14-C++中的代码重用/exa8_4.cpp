// 功能：本例属于多态的范畴
// 当派生类和基类具有同名的方法时，派生类对象将使用派生类的方法，还是基类的方法？
// 参考资料：[例8-4 通过虚函数实现运行时多态](https://next.xuetangx.com/learn/THU08091000248/THU08091000248/1510503/video/1246288)
// 说明：在编译时不决定用哪个方法，而是在运行时决定用哪个方法，具体做法是添加virtual。与exa7_3.cpp进行比较
#include <iostream>
using namespace std;

// 基类Base1
class Base1
{
private:
    /* data */
public:
    virtual void display() const
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
    // 这里写不写virual无所谓，增强代码可读性，最好还是要写上
    virtual void display() const { cout << "Base2::display()" << endl; }
};

// 派生类Derived
class Derived : public Base2
{
public:
    // 这里写不写virual无所谓，增强代码可读性，最好还是要写上
    virtual void display() const { cout << "Derived display()" << endl; }
};

void fun(Base1 *ptr)
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