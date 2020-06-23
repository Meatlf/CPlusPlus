// Example03
// 说明：protected成员举例
#include <iostream>

class A
{
protected:
    int x;
};

class B : public A
{
public:
    void function();
};

void B::function()
{
    x = 5; // 正确
}

int main()
{
    // A a;
    // a.x = 5;    // 错误
    return 0;
}