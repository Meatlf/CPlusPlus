// complex0.cpp -- Complex methods
#include <iostream>
using std::cout;
#include "complex0.h"

complex::complex(const double re, const double im)
{
    re_ = re;
    im_ = im;
}

complex::complex()
{
    re_ = 0;
    im_ = 0;
}

complex::~complex()
{
}

complex complex::operator+(const complex c)
{
    complex sum;
    sum.re_ = re_ + c.re_;
    sum.im_ = im_ + c.im_;
    return sum;
}

complex complex::operator-(const complex c)
{
    complex del;
    del.re_ = re_ - c.re_;
    del.im_ = im_ - c.im_;
    return del;
}

complex complex::operator*(const complex c)
{
    complex mul;
    mul.re_ = re_ * c.re_ - im_ * c.im_;
    mul.im_ = re_ * c.im_ + im_ * c.re_;
    return mul;
}

complex operator*(const double x, const complex c)
{
    complex mul;
    mul.re_ = x * c.re_;
    mul.im_ = x * c.im_;
    return mul;
}

complex complex::operator~()
{
    return complex(-re_, -im_);
}

std::istream &operator>>(std::istream &is, complex &c)
{
    cout << "real: ";
    is >> c.re_;
    cout << "imaginary: ";
    is >> c.im_;
    return is;
}

std::ostream &operator<<(std::ostream &os, const complex &c)
{
    os << "(" << c.re_ << "," << c.im_ << "i)";
    return os;
}
