// exercise2.cpp
// 说明：相关技术有：引用
#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string name;
    double weight;
    int calories;
};

void set(CandyBar &candyBar, string name, double weight, int calories);
void show(const CandyBar &candyBar);

void set(CandyBar &candyBar, string name, double weight, int calories)
{
    candyBar.name = name;
    candyBar.weight = weight;
    candyBar.calories = calories;
}

void show(const CandyBar &candyBar)
{
    cout << candyBar.name << endl;
    cout << candyBar.weight << endl;
    cout << candyBar.calories << endl;
}

int main()
{
    string name = "Meatlf";
    double weight = 140.5;
    int calories = 5000;
    CandyBar candyBar;
    set(candyBar, name, weight, calories);
    show(candyBar);
    // cin.get();
    return 0;
}