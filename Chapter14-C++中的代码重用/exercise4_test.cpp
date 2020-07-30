#include <iostream>
#include "class4.h"

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;

    // 下面这条语句会报错，因为无法声明抽象类的对象
    // Person p;
    Gunslinger g;
    g.Show();
    cout << "Bye\n";
    return 0;
}