// exercise01.cpp -- using the ctype.h library
#include <iostream>
#include <cctype> // prototypes for character functions
int main()
{
    using namespace std;
    cout << "Enter text for analysis, and type @"
            " to terminate input.\n";
    char ch;

    cin.get(ch);      // get first character
    while (ch != '@') // test for sentinel
    {
        if (islower(ch))
            ch = toupper(ch);
        else if (isupper(ch))
            ch = tolower(ch);

        cin.get(ch); // get next character
    }
    // cin.get();
    // cin.get();
    return 0;
}
