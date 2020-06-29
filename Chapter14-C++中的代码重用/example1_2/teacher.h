// teacher.h -- defining a Teacher class using containment
#ifndef TEACHER_H_
#define TEACHER_H_

#include <iostream>
#include <string>
#include <valarray>
// 功能：熟悉包含对象成员的类
// 参考资料：书本"14.1 包含对象成员的类"
class Teacher
{
private:
    typedef std::valarray<int> ArrayDb;
    std::string name;    // contained object
    ArrayDb performance; // contained object

public:
    Teacher() : name("Null Teacher"), performance() {}
    Teacher(const std::string &s, const ArrayDb &a) : name(s), performance(a) {}
    ~Teacher() {}
    double Average() const;
    void Show() const;
};

#endif
