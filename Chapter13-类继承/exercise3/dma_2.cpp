// dma.cpp --dma class methods

#include "dma_2.h"
#include <cstring>

// ABC方法
ABC::ABC(const char *l, int r)
{
    label = new char[std::strlen(l) + 1];
    std::strcpy(label, l);
    rating = r;
}

ABC::ABC(const ABC &a)
{
    label = new char[std::strlen(a.label) + 1];
    std::strcpy(label, a.label);
    rating = a.rating;
}

ABC::~ABC()
{
    delete[] label;
}

void ABC::View() const
{
    std::cout << "label: " << label << std::endl;
    std::cout << "rating: " << rating << std::endl;
}

ABC &ABC::operator=(const ABC &a)
{

    if (this == &a)
        return *this;
}

std::ostream &operator<<(std::ostream &os, const ABC &a)
{
    os << a.label << ", " << a.rating;
    return os;
}

// baseDMA methods
baseDMA::baseDMA(const char *l, int r) : ABC(l, r)
{
}

std::ostream &operator<<(std::ostream &os, const baseDMA &rs)
{
    os << (const ABC &)rs;
    return os;
}

// lacksDMA methods
lacksDMA::lacksDMA(const char *c, const char *l,
                   int r) : ABC(l, r)
{
    std::strcpy(color, c);
}

lacksDMA::lacksDMA(const char *c, const ABC &a)
    : ABC(a)
{
    std::strcpy(color, c);
}

void lacksDMA::View() const
{
    ABC::View();
    std::cout << color << std::endl;
}

std::ostream &operator<<(std::ostream &os, const lacksDMA &ls)
{
    os << (const baseDMA &)ls;
    os << "Color: " << ls.color << std::endl;
    return os;
}

// hasDMA methods
hasDMA::hasDMA(const char *s, const char *l, int r)
    : ABC(l, r)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const char *s, const ABC &a)
    : ABC(a)
{
    style = new char[std::strlen(s) + 1];
    std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA &hs)
    : ABC(hs) // invoke base class copy constructor
{
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
}

hasDMA::~hasDMA()
{
    delete[] style;
}

hasDMA &hasDMA::operator=(const hasDMA &hs)
{
    if (this == &hs)
        return *this;
    ABC::operator=(hs); // copy base portion
    delete[] style;     // prepare for new style
    style = new char[std::strlen(hs.style) + 1];
    std::strcpy(style, hs.style);
    return *this;
}

void hasDMA::View() const
{
    ABC::View();
    std::cout << style << std::endl;
}

std::ostream &operator<<(std::ostream &os, const hasDMA &hs)
{
    os << (const ABC &)hs;
    os << "Style: " << hs.style << std::endl;
    return os;
}
