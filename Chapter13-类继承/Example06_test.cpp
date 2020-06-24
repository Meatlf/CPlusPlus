// Example05
// 功能：单继承派生构造函数举例
// 说明：
#include <iostream>
using namespace std;

class B
{
public:
    B();
    B(int i);
    ~B();
    void print() const;

private:
    int b;
};

B::B()
{
    b = 0;
    cout << "B's default constructor called." << endl;
}

class C : public B
{
public:
    C();
    C(int i, int j);
    void display() const { cout << "Base2::display()" << endl; }
};

class Derived : public Base2
{
public:
    void display() const { cout << "Derived::display()" << endl; }
};

void fun(Base1 *ptr) { ptr->display(); }

int main()
{
    Base1 base1;
    Base2 base2;
    Derived derived;

    fun(&base1);
    fun(&base2);
    fun(&derived);
}
