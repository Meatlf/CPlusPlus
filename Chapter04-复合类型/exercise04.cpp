#include <iostream>
#include <string>               // make string class available
int main()
{
    using namespace std;
    string s1;
    string s2, s3;

    cout << "Enter your first name: ";
    cin >> s1;
    cout << "Enter your last name: ";
    cin >> s2;
    cout << "Here's the information in a single string: " << s1 << ", " << s2 << endl;
    //cin.get();
    return 0; 
}
