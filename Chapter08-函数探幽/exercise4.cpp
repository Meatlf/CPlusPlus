// exercise4.cpp
// 说明：
#include <iostream>
using namespace std;
#include <cstring> // for strlen(), strcpy()

struct stringy
{
    char *str;
    int ct;
};

void set(string beany, char *testing);
void show(string beany, char *testing);

void set(string beany, char *testing)
{
    beany = "ffdsfsdfsdfsdf";
    strcpy(testing, "fdsfdsfsdf");
}

void show(string beany, int times = 1)
{
    cout << beany << endl;
}

int main()
{
    string beany;
    char testing[] = "Reality isn't what it used to be.";
    set(beany, testing);
    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'D';
    show(testing);
    show(testing, 3);
    show("Done!");

    // cin.get();
    return 0;
}