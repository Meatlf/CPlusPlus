// instr2.cpp -- reading more than one word with getline
#include <iostream>

using namespace std;

void use_getline();
void dont_use_getline();

// 使用getline
void use_getline()
{
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin.getline(name, ArSize); // reads through newline
    cout << "Enter your favorite dessert:\n";
    cin.getline(dessert, ArSize);
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
}

// 不使用getline
void dont_use_getline()
{
    const int ArSize = 20;
    char name[ArSize];
    char dessert[ArSize];

    cout << "Enter your name:\n";
    cin >> name;
    cout << "Enter your favorite dessert:\n";
    cin >> dessert;
    cout << "I have some delicious " << dessert;
    cout << " for you, " << name << ".\n";
}

int main()
{
    use_getline();
    cout << endl;
    dont_use_getline();
    // cin.get();
    return 0;
}
