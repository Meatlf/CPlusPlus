// exercise3.cpp -- using placement new
#include <iostream>
#include <cstring>
#include <new> // for placement new
const int BUF = 512;
const int N = 50;
char buffer[BUF]; // chunk of memory

struct chaff
{
    char dross[20];
    int slag;
};

int main()
{
    using namespace std;

    chaff *pChaff1, *pChaff2;
    int i;
    cout << "Calling new and placement new:\n";
    pChaff1 = new chaff[2];
    pChaff2 = new (buffer) chaff[2];

    for (i = 0; i < 2; i++)
    {
        char c1[N];
        int number;
        cin >> c1 >> number;
        strcpy(pChaff1[i].dross, c1);
        pChaff1[i].slag = number;

        cin >> c1 >> number;
        strcpy(pChaff2[i].dross, c1);
        pChaff2[i].slag = number;
    }

    for (i = 0; i < 2; i++)
    {
        cout << pChaff1[i].dross << " " << pChaff1[i].slag << endl;
        cout << pChaff2[i].dross << " " << pChaff2[i].slag << endl;
    }

    delete[] pChaff1;
    // 使用下面的语句会报错
    // delete[] pChaff2;
    // cin.get();
    return 0;
}
