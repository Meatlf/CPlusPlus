// teacher.cpp -- Teacher class using containment
#include "teacher.h"
using std::endl;
using std::istream;
using std::ostream;
using std::string;

//public methods
double Teacher::Average() const
{
    if (performance.size() > 0)
        return performance.sum() / performance.size();
    else
        return 0;
}

void Teacher::Show() const
{
    std::cout << "名字："<<name << std::endl;
    std::cout << "第一个元素的值："<<performance[0] << std::endl;
}
