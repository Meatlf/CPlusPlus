// studenti.cpp -- Student class using private inheritance
#include "studenti.h"
using std::endl;
using std::istream;
using std::ostream;
using std::string;

// public methods
// 在派生类Student中使用作用域解析运算符来调用基类的公有方法，
// 具体来讲：ArrayDb::size() 和ArrayDb::sum()
double Student::Average() const
{
    if (ArrayDb::size() > 0)
        return ArrayDb::sum() / ArrayDb::size();
    else
        return 0;
}

const string &Student::Name() const
{
    return (const string &)*this;
}

double &Student::operator[](int i)
{
    return ArrayDb::operator[](i); // use ArrayDb::operator[]()
}

double Student::operator[](int i) const
{
    return ArrayDb::operator[](i);
}

// private method
ostream &Student::arr_out(ostream &os) const
{
    int i;
    int lim = ArrayDb::size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << ArrayDb::operator[](i) << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
            os << endl;
    }
    else
        os << " empty array ";
    return os;
}

// friends
// use String version of operator>>()
istream &operator>>(istream &is, Student &stu)
{
    is >> (string &)stu;
    return is;
}

// use string friend getline(ostream &, const string &)
istream &getline(istream &is, Student &stu)
{
    getline(is, (string &)stu);
    return is;
}

// use string version of operator<<()
ostream &operator<<(ostream &os, const Student &stu)
{
    os << "Scores for " << (const string &)stu << ":\n";
    stu.arr_out(os); // use private method for scores
    return os;
}
