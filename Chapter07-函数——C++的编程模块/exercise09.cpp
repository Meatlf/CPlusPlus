//exercise09.cpp --
#include <iostream>
#include <cstring>
using namespace std;
const int SLEN = 4;

struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);

void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main()
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;
    while (cin.get() != '\n')
        continue;
    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);
    delete[] ptr_stu;
    cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    char *pName = new char[10];
    char *pHobby = new char[10];
    int ooplevel = 0;
    int i = 0;
    while (i < n && cin >> pName && cin >> pHobby && cin >> ooplevel && *pName != 'q')
    {
        strcpy(pa[i].fullname, pName);
        strcpy(pa[i].hobby, pHobby);
        pa[i].ooplevel = ooplevel;
        i++;
    }
    delete[] pHobby;
    delete[] pName;
    return i;
}

void display1(student st) { cout << st.fullname << " " << st.hobby << " " << st.ooplevel << endl; }
void display2(const student *ps) { cout << ps->fullname << " " << ps->hobby << " " << ps->ooplevel << endl; }
void display3(const student pa[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << pa[i].fullname << " " << pa[i].hobby << " " << pa[i].ooplevel << endl;
    }
}
