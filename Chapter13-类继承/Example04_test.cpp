// Example04
// 说明：多继承举例
#include <iostream>

class A
{
public:
    void setA(int);
    void showA() const;

private:
    int a;
};

class B
{
public:
    void setB(int);
    void showB() const;

private:
    int b;
};

class C : public A, private B
{
public:
    void setC(int, int, int);
    void showC() const;

private:
    int c;
};

int main()
{
    // A a;
    // a.x = 5;    // 错误
    return 0;
}

void A::setA(int x) { a = x; }
void B::setB(int x) { b = x; }
void C::setC(int x, int y, int z)
{
    setA(x);
    setB(y);
    c = z;
}

int main()
{
    C obj;
    obj.setA(5);
    obj.showA();
    obj.setC(6, 7, 9);
    obj.showC();
    // obj.setB(6);    // 错误
    // obj.showB();    // 错误
}