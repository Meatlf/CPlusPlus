// exercise09.cpp --
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int i = 0;

    cout << "Enter words (to stop, type the word done):" << endl;
    while (cin >> s && s != "done")
    {
        i++;
    }
    cout << "You entered a total of " << i << " words." << endl;
    // std::cin.get();
    return 0;
}