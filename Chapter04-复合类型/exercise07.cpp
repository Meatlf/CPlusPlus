// exercise07.cpp
#include <iostream>
#include <string> // make string class available
#include <cstring>

using namespace std;

struct Pizza
{
    string company;
    float diameter;
    float weight;
};

int main()
{
    Pizza snack[2];
    cout << "请输入2个关于Pizza的信息：" << endl;
    for (int i = 0; i < 2; i++)
    {
        cin >> snack[i].company >> snack[i].diameter >> snack[i].weight;
    }

    for (int i = 0; i < 2; i++)
    {
        cout << snack[i].company << " " << snack[i].diameter
             << " "
             << snack[i].weight << endl;
    }

    return 0;
}
