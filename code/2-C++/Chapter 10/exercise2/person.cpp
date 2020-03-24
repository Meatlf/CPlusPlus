#include "person.h"

Person::Person ()
{
    lname = "What's your last name ?";
    strcpy(fname, "What's your first name ?");
}

Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
}

void Person::Show() const
{
    cout << "fname: " << fname << " lname: " << lname;
}

void Person::Forma1Show() const
{
    cout << "lname: " << lname << " fname: " << fname;
}

Person::~Person()
{

}          
