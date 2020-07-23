#include "plorg.h"

using namespace std;

int main()
{
    Plorg plorgr0 = Plorg();

    plorgr0.showPlorg();
    plorgr0.setCI(60);
    plorgr0.showPlorg();

    char name[19];
    int CI;
    cout << "请收入Name：";
    cin >> name;
    cout << "请输入CI：";
    cin >> CI;
    Plorg plorgr1 = Plorg(name, CI);

    plorgr1.showPlorg();
    plorgr1.setCI(60);
    plorgr1.showPlorg();

    return 0;
}