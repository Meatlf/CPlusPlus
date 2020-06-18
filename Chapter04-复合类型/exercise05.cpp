// 习题5和习题6的结合版代码
#include <iostream>
#include <string>               // make string class available
#include <cstring>

using namespace std;

struct CandyBar
{
    string brandName;
    float weight;
    int calories;
};

int main()
{
    CandyBar snack[2] 
        {{"Mocha Munch", 2.3, 350},
         {"Mitch Geroge", 5.3, 340}
        };
    cout << snack[0].brandName << " "<< snack[0].weight
        << " " 
        << snack[0].calories << endl;

    cout << snack[1].brandName << " "<< snack[1].weight
    << " " 
    << snack[1].calories << endl;

    return 0; 
}
