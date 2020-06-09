// stacker.cpp -- testing the Stack class
#include <iostream>
#include <cctype>  // or ctype.h
#include "stack.h"

#define TEST_BY_Meatlf 1

int main()
{
#if TEST_BY_Meatlf
    Stack st;   // create an empty stack
    
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    int p0 = 1;
    st.push(p0);
    std::cout << "Push:" << p0 << std::endl;
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    int p1 = 2;
    st.push(p1);
    std::cout << "Push:" << p1 << std::endl;
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    
    int p2 = 3;
    st.push(p2);
    std::cout << "Push:" << p2 << std::endl;
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    st.push(4);
    std::cout << st.isempty() << std::endl;
    std::cout << st.isfull() << std::endl << std::endl;

    Item i;
    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;
    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;
    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;
    std::cout << st.pop(i) << std::endl;
    std::cout << "Pop:" << i << std::endl;
    return 0;
#elif
    using namespace std;
    Stack st; // create an empty stack
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
        << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')   
            continue;
        if (!isalpha(ch))
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
                       }
                       break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0; 
#endif
}
