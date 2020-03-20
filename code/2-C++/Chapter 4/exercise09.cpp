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
    CandyBar* snack = new CandyBar [2];

    snack[0].brandName="Mocha Munch";
    snack[0].weight = 2.3;
    snack[0].calories = 350;
 
    snack[1].brandName="Jordan";
    snack[1].weight = 3.3;
    snack[1].calories = 850;

    cout << snack[0].brandName << " "<< snack[0].weight
        << " " 
        << snack[0].calories << endl;

    cout << snack[1].brandName << " "<< snack[1].weight
    << " " 
    << snack[1].calories << endl;

    delete [] snack;
    return 0; 
}
