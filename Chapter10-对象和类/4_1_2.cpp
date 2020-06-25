#include <iostream>
using namespace std;

class Clock
{
private:
    int hour, minute, second;

public:
    // 自定义默认构造函数
    Clock();
    // 自定义构造函数
    Clock(int newH, int newM, int newS);
    void setTime(int newH, int newM, int newS);
    void showTime();
};

Clock::Clock() : hour(0), minute(0), second(0) {}

Clock::Clock(int newH, int newM, int newS) : hour(newH), minute(newM), second(newS)
{
}

void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}

void Clock::showTime()
{
    cout << hour << ":" << minute << ":" << second;
}

int main()
{
    Clock c1(0, 0, 0);
    c1.showTime();
    Clock c2;
    c2.showTime();
    return 0;
}
