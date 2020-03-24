// static.cpp -- using a static local variable
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string input;

    cout << "Enter a line:\n";
    // cin >> input;        // 如何使用这条语句将无法处理空行
    getline(cin, input);

    static int total = 0;        // static local variable

    while (input.size())
    {
        cout << input << " contains " << input.size() << endl;
        total += input.size();
        // cin >> input;
        cout << "Enter a line:\n";
        getline(cin, input);
    }
    cout << total << " characters total\n";
    cout << "Bye\n";
    return 0;
}