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

VintagePort::VintagePort() : Port()
{
    nickname = new char[100];
    year = 10;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "none", b)
{
    nickname = new char[100];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort &vp) : Port(vp)
{
    nickname = new char[100];
    strcpy(nickname, vp.nickname);
    year = vp.year;
}

VintagePort &VintagePort::operator=(const VintagePort &vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete[] nickname;
    strcpy(nickname, vp.nickname);
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    cout << nickname << year << endl;
}

ostream &operator<<(ostream &os, const VintagePort &vp)
{
    os << (const Port &)vp;
    os << "Nick name: " << vp.nickname << " Year: " << vp.year << endl;
    return os;
}