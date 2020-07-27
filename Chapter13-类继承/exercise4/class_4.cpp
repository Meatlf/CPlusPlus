// class_4.cpp

#include "class_4.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b)
{
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port &p)
{
    // 这里不需要以下注释的语句
    // delete[] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
}

Port &Port::operator=(const Port &p)
{
    if (this == &p)
        return *this;
    delete[] brand;
    brand = new char[strlen(p.brand) + 1];
    strcpy(brand, p.brand);
    strcpy(style, p.style);
    bottles = p.bottles;
    return *this;
}

Port &Port::operator+=(int b)
{
    this->bottles += b;
    return *this;
}

void Port::Show() const
{
    cout << "品牌名为：" << brand << " 风格为：" << style << " 酒的瓶数为：" << bottles << endl;
}

ostream &operator<<(ostream &os, const Port &p)
{
    os << "品牌名为：" << p.brand << " 风格为：" << p.style << " 酒的瓶数为：" << p.bottles << endl;
    return os;
}