// exercise08.cpp --
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char *s = new char[100];
    int i = 0;

    cout << "Enter words (to stop, type the word done):" << endl;
    while (cin >> s && strcmp(s,"done"))
    {
        i++;
    }
    cout << "You entered a total of " << i << " words." << endl;
    // std::cin.get();
    return 0;
}