#include <iostream>
using namespace std;
#include "classic.h"

void Bravo(const Cd &disk);

int main()
{
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano", "Alfred", "Philips", 2, 57.17);

    Cd *pcd = &c1;

    cout << "Using object directly:\n";
    // 调用基类的Report()方法
    c1.Report();
    // 调用派生类的Report()方法
    c2.Report();

    cout << "Using type cd * pointer to objects:\n";
    // 调用基类的Report()方法
    pcd->Report();
    pcd = &c2;
    // 调用派生类的Report()方法
    pcd->Report();

    cout << "Calling a function with a Cd reference argument:\n";
    // 在Bravo()函数中调用基类的Report()方法
    Bravo(c1);
    // 在Bravo()函数中调用派生类的Report()方法
    Bravo(c2);

    cout << "Testing assignment: ";
    Classic copy;
    copy = c2;
    copy.Report();

    return 0;
}

void Bravo(const Cd &disk)
{
    disk.Report();
}
