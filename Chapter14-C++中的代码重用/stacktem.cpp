// stacktem.cpp -- testing the template stack class
#include <iostream>
#include <string>
#include <cctype>
#include "stacktp.h"
using std::cin;
using std::cout;

#define TEST_BY_Meatlf 1
int main()
{
#if TEST_BY_Meatlf
    Stack<unsigned long> st;   // create an empty stack
    unsigned long p0 = 1,p1 = 2,p2 = 3,p3 = 4;
    unsigned long i;

    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    st.push(p0);
    std::cout << "Push:" << p0 << std::endl;
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    st.push(p1);
    std::cout << "Push:" << p1 << std::endl;
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    st.push(p2);
    std::cout << "Push:" << p2 << std::endl;
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    st.push(p3);
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;
    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;
    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;
    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;

    Stack<int*> st1;
    int i0 = 3;
    int i1 = 3;
    int* pi0 = &i0;
    int* pi1 = &i1;
    int* po0;

    std::cout << "Push:" << pi0 << std::endl;
    std::cout << st1.isempty() << std::endl;
    std::cout << st1.isfull() << std::endl << std::endl;

    std::cout << "Push:" << pi1 << std::endl;
    std::cout << st1.isempty() << std::endl;
    std::cout << st1.isfull() << std::endl << std::endl;


    std::cout << st1.pop(po0) << std::endl;
    std::cout << "Pop:" << po0 << std::endl;

    return 0;
#else
    Stack<std::string> st;   // create an empty stack
    char ch;
    std::string po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && std::toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!std::isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.isfull())
                          cout << "stack already full\n";
                      else
                          st.push(po);
                      break;
            case 'P':
            case 'p': if (st.isempty())
                          cout << "stack already empty\n";
                      else {
                          st.pop(po);
                          cout << "PO #" << po << " popped\n";
                          break;
                      }
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    // cin.get();
    // cin.get();
    return 0; 
#endif
}
