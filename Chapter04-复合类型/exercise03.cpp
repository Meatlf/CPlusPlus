#include <iostream>
#include <cstring>

int main()
{
    using namespace std;
    const int Size = 15;
    char first_name[Size];
    char last_name[Size];

    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> last_name;
    cout << "Here's the information in a single string: " << first_name << ",  " << last_name << endl;
    // cin.get();
    return 0;
}
