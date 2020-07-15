// exercise3.cpp
// 说明：
#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string name;
    double weight;
    int calories;
};

void toupper_test(string &str);

void toupper_test(string &str)
{
    int i = 0;
    while (str[i])
    {
        str[i] = toupper(str[i]);
        i++;
    }
}

int main()
{
    string str;
    char c[100];
    cout << "Enter a string (q to quit): ";
    cin.getline(c, 100);
    str = c;
    while (str != "q")
    {
        toupper_test(str);
        cout << str << endl;
        cout << "Next string (q to quit): " << endl;
        cin.getline(c, 100);
        str = c;
    }
    // cin.get();
    return 0;
}