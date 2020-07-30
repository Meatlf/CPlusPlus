// workmi.cpp -- multiple inheritance
// compile with workermi.cpp
#include <iostream>
#include <cstring>
#include "workermi.h"
const int SIZE = 5;

int main()
{
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker *lolas[SIZE];

    int ct;
    for (ct = 0; ct < SIZE; ct++)
    {
        char choice;
        cout << "Enter the employee category:\n"
             << "w: waiter  s: singer  "
             << "t: singing waiter  q: quit\n";
        cin >> choice;
        // Q：如何理解 strchr？
        // A：以下面的语句为例，当choice为"wstq"中的任意一个元素时，返回值不为空
        while (strchr("wstq", choice) == NULL)
        {
            cout << "Please enter a w, s, t, or q: ";
            cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice)
        {
        case 'w':
            // Q:如何理解如下的语句？
            // A：使用new初始化一个类对象，注意，在此过程中调用了默认构造函数。
            lolas[ct] = new Waiter;
            break;
        case 's':
            lolas[ct] = new Singer;
            break;
        case 't':
            // Q：下面的这条语句到底执行了什么？
            // A：初始化了一个指向SingingWaiter对象，首先调用Worker默认构造函数，
            // 然后调用Singer默认构造函数，最后调用Waiter默认构造函数
            lolas[ct] = new SingingWaiter;
            break;
        }
        cin.get();
        lolas[ct]->Set();
    }

    cout << "\nHere is your staff:\n";
    int i;
    for (i = 0; i < ct; i++)
    {
        cout << endl;
        lolas[i]->Show();
    }
    for (i = 0; i < ct; i++)
        delete lolas[i];
    cout << "Bye.\n";
    // cin.get();
    // cin.get();
    return 0;
}
