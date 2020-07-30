// 功能：例8-5 虚析构函数举例 本例属于多态的范畴
// Q：为什么需要虚析够函数？
// A：如果你打算允许其他人通过基类指针调用对象的析构函数（通过delete这样做是正常的），
// 就需要让基类的析构函数成为虚函数，否则执行delete的结果是不确定的。
// 参考资料：[例8-5 虚析构函数举例](https://next.xuetangx.com/learn/THU08091000248/THU08091000248/1510503/video/1246290)
// 说明：
#include <iostream>
using namespace std;

// 基类Base
class Base
{
private:
    /* data */
public:
    virtual ~Base(); // 不是虚函数
};

Base::~Base()
{
    cout << "Base destructor" << endl;
}

// 派生类Derived
class Derived : public Base
{
public:
    Derived();
    virtual ~Derived(); // 不是虚函数
private:
    int *p;
};

Derived::Derived()
{
    p = new int(0);
}

Derived::~Derived()
{
    cout << "Derived destructor" << endl;
    delete p;
}

void fun(Base *b)
{
    delete b; // 静态绑定，只会调用～Base()
}

int main()
{
    Base *b = new Derived();
    fun(b);
    return 0;
}