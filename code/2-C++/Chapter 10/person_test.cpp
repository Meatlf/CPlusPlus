#include "person.h"
#include <iostream>

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy","Sam");
    
    one.Show();
    cout << endl;
    one.Forma1Show();
    cout << endl << endl;

    two.Show();
    cout << endl;
    two.Forma1Show();
    cout << endl << endl;

    three.Show();
    cout << endl;
    three.Forma1Show();
    cout << endl << endl;
}