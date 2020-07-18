// exercise07.cpp --
#include <iostream>
#include <cstring>

using namespace std;

const int Number = 10;
const int CharLenth = 50;

struct car
{
    char *producer;
    int year;
};

int main()
{
    car *pCar = new car[Number];

    int n;

    cout << "How many cars do you wish to catalog? ";
    cin >> n;
    if (n > Number)
    {
        cout << "请输入小于10的数！" << endl;
        return 0;
    }
    cin.get();
    for (int i = 0; i < n; i++)
    {
        cout << "Car #" << i << ":" << endl;
        cout << "Please enter the make: ";
        pCar[i].producer = new char[CharLenth];
        cin.getline(pCar[i].producer, CharLenth);
        cout << "Please enter the year made: ";
        cin >> pCar[i].year;
        cin.get();
    }
    cout << "Here is your collection:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << pCar[i].year << " " << pCar[i].producer << endl;
        delete[] pCar[i].producer;
    }
    // std::cin.get();
    return 0;
}