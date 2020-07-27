// Lister.cpp -- testing the List class
#include <iostream>
#include <cctype>  // or ctype.h
#include "list.h"

#define TEST_BY_Meatlf 1

int main()
{
#if TEST_BY_Meatlf
    List st;   // create an empty List
    
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
    List st; // create an empty List
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
                           cout << "List already full\n";
                       else
                           st.push(po);
                       break;
             case 'P':
             case 'p': if (st.isempty())
                           cout << "List already empty\n";
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
