#include <iostream>
#include <string>
#include <cstring>

int main()
{
    using namespace std;

    string first_name;
    string last_name;
    char grade;
    unsigned int age;

    cout << "What is your first name?";
    getline(cin, first_name);
    cout << "What is your last name? ";
    getline(cin, last_name);
    cout << "What letter grade do you deserve? ";
    // getline(cin, grade);
    cin >> grade;
    cout << "What is your age? ";
    // getline(cin, age);
    cin >> age;
    cout << "Name:  " << last_name << ", " << first_name << endl;
    cout << "Grade: " << char(grade + 1) << endl;
    cout << "Age: " << age << endl;
    // cin.get();
    return 0;
}
