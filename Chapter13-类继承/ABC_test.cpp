//
// 功能：ABC概念
// 说明：抽象基类的学习
// 参考资料：书本"13.6 抽象基类"
#include <iostream>
using namespace std;

// 抽象基类
class myABC
{
private:
    std::string fullName;
    int age_;
    int number_;

public:
    myABC(const std::string &s = "NUllbody", int age = 20, int number = 10) : fullName(s), age_(age), number_(number){};
    // 抽象基类
    virtual void addBooks(int number) = 0;
    virtual void show() = 0;
    // 容易忘记添加{}
    virtual ~myABC(){};
};

// 派生类A
class myA : public myABC
{
private:
    int field_;

public:
    myA(const std::string &s = "NUllbody", int age = 20, int number = 10, int field = 2) : myABC(s, age, number), field_(field){};
    void addBooks(int number);
    void show();
    virtual ~myA(){};
};

// 派生类B
class myB : public myABC
{
private:
    double money_;

public:
    myB(const std::string &s = "NUllbody", int age = 20, int number = 10, int money = 6000) : myABC(s, age, number), money_(money){};
    void addBooks(int number);
    void show();
    virtual ~myB(){};
};

void myABC::addBooks(int number)
{
    number_ += number;
}

void myABC::show()
{
    std::cout << "名字：" << fullName << " 年龄：" << age_ << " 书本的数量：" << number_;
}

void myA::addBooks(int number)
{
    if (number < 5)
        std::cout << " 不可以增加小于5本的书！";
    else
        myABC::addBooks(number);
}

void myA::show()
{
    myABC::show();
    std::cout << " 田的亩数：" << field_ << std::endl;
}

void myB::addBooks(int number)
{
    if (number < 10)
        std::cout << " 不可以增加小于10本的书！";
    else
        myABC::addBooks(number);
}

void myB::show()
{
    myABC::show();
    std::cout << "田的亩数：" << money_ << std::endl;
}

int main()
{
    // 如果写成 myABC abc[2]; 会报错
    myABC *abc[2];

    abc[0] = new myA("Meatlf", 25, 100, 20);
    abc[0]->addBooks(6);
    abc[0]->show();

    abc[1] = new myB("Jobs", 29, 200, 30);
    abc[1]->addBooks(6);
    abc[1]->show();

    return 0;
}