// exercise3.cpp
// 说明：
#include <iostream>
#include <string>

using namespace std;

struct CandyBar
{
    string name;
    double weight;
    int calories;
};

string *toupper_test(const string *&str);

string *toupper_test(const string *&str)
{
    int i = 0;
    string *result_str;
    while ((*str)[i])
    {
        (*result_str)[i] = toupper((*str)[i]);
        i++;
    }
    return result_str;
}

int main()
{
    string str = "Meatlf";
    const string *pstr = &str;
    string* out_string = toupper_test(pstr);
    cout << *out_string << endl;
    // cin.get();
    return 0;
}