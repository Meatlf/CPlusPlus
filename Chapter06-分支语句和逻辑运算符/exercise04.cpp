// exercise04.cpp -- non-numeric input terminates loop
// 参考资料:
// switch.cpp -- using the switch statement
#include <iostream>
using namespace std;
void showmenu(); // function prototypes
void remind();

const int strsize = 50;

struct bop
{
    char fullname[strsize];
    char title[strsize];
    char bopname[strsize];
    int preference;
};

int main()
{
    showmenu();
    char choice;
    remind();
    cin >> choice;
    bool flag = true;
    while (flag)
    {
        switch (choice)
        {
        case 'c':
            cout << "I dont know about carnivore\n";
            flag = false;
            break;
        case 'p':
            cout << "I want to be a pianist\n";
            flag = false;
            break;
        case 't':
            cout << "A maple is a tree\n";
            flag = false;
            break;
        case 'g':
            cout << "Playing game is happy\n";
            flag = false;
            break;
        default:
            remind();
            cin >> choice;
        }
    }
    // cin.get();
    // cin.get();
    return 0;
}

void showmenu()
{
    cout << "Please enter one of the following choices:\n"
            "c) carnivors       p) pianist\n"
            "t) tree            g) game\n"
            "";
}
void remind()
{
    cout << "Please enter a c, p, t, or g: ";
}