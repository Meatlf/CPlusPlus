// exercise5.cpp --
#include <iostream>
int main()
{
    using namespace std;
    long long worldPopulation;
    long long USPopulation;
    cout << "Enter the world's population: ";
    cin >> worldPopulation;
    cout << "Enter the population of US: ";
    cin >> USPopulation;

    cout << "The population of US is " << (float)USPopulation / (float)worldPopulation * 100 << "% of the world population." << endl;

    // cin.get();
    return 0;
}
