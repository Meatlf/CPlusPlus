// exercise02.cpp -- non-numeric input terminates loop
// 参考资料：6.7 读取数字的循环
#include <iostream>
const int Max = 10;
int main()
{
    using namespace std;
    // get data
    double number[Max];
    double average;
    int biggerThanAverage = 0;
    cout << "Please enter the number.\n";
    cout << "You may enter up to " << Max
         << " number <q to terminate>.\n";
    cout << "number #1: ";
    int i = 0;
    while (i < Max && cin >> number[i])
    {
        if (++i < Max)
            cout << "number #" << i + 1 << ": ";
    }
    // calculate average
    double total = 0.0;
    for (int j = 0; j < i; j++)
        total += number[j];
    // report results
    if (i == 0)
        cout << "No number\n";
    else
    {
        average = total / i;
        cout << average << " = average weight of "
             << i << " number\n";
        for (int k = 0; k < i; k++)
            if (number[k] > average)
                biggerThanAverage++;
        cout << biggerThanAverage << " numbers are bigger than average." << endl;
    }
    cout << "Done.\n";
    // code to keep VC execution window open if q is entered
    //	if (!cin)  // input terminated by non-numeric response
    //	{
    //	    cin.clear();  // reset input
    //	    cin.get();    // read q
    //	}
    //	cin.get();    // read end of line after last input
    //	cin.get();    // wait for user to press <Enter>
    return 0;
}
