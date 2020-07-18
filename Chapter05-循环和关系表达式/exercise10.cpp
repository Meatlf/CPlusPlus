// exercise10.cpp --
#include <iostream>

using namespace std;

int main()
{
    int n;

    cout << "Enter number of rows: ";
    cin >> n;

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j + i < n; j++)
            cout << ".";
        for (int k = 0; k < i; k++)
            cout << "*";
        cout << endl;
    }
    // std::cin.get();
    return 0;
}