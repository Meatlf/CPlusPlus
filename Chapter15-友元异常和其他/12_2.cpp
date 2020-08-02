// 12_2.cpp -- 带析构语义的类的C++异常处理
// Q：C++在try块中监视异常，一旦有异常则去执行异常去了，后面的内容就不执行了，
// 如果先执行了构造函数，那何时执行析构函数呢？
// A：C++将从对应的try块开始到异常被抛掷处之间构造（且尚未析构）的所有自动对象进行析构。
#include <iostream>
#include <string>
using namespace std;

// 异常类
class MyException
{
public:
    MyException(const string &messages) : messages(messages) {}
    ~MyException() {}
    const string &getMessage() const { return messages; }

private:
    string messages;
};

class Demo
{
public:
    Demo()
    {
        cout << "Constructor of Demo" << endl;
    }
    ~Demo() { cout << "Destructor of Demo" << endl; }
};

// 该函数有可能抛出MyExcepton的异常
void func() throw(MyException)
{
    // 对象d如何析构呢？
    Demo d;
    cout << "Throw MyException in func()" << endl;
    throw MyException("exception thrown by func()");
}

int main()
{
    cout << "In main function" << endl;
    try
    {
        func();
    }
    catch (MyException &e)
    {
        cout << "Caught an exception: " << e.getMessage() << endl;
    }
    cout << "Resume the execution of main()" << endl;
    return 0;
}