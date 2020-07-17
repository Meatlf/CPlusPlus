// exercise4.cpp --
#include <iostream>
int main()
{
    using namespace std;
    long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    cout << seconds << " seconds = " << seconds / 24 / 60 / 60 << " days, "
         << (seconds / 60 / 60) % 24 << " hours, "
         << seconds / 60 % 60 << " minutes, "
         << seconds % 60 << " seconds" << endl;
    // cin.get();
    return 0;
}
