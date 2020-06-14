// complex0.h -- definition for the Complex0 class
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
class complex
{
private:
    double re_; // 实部
    double im_; // 虚部
public:
    complex(const double re, const double im); // constructor
    complex();                     // default constructor
    ~complex();
    complex operator+(const complex c);
    complex operator-(const complex c);
    complex operator*(const complex c);
    friend complex operator*(const double x, const complex c);
    complex operator~();
    friend std::istream &operator>>(std::istream &os, complex &c);
    friend std::ostream &operator<<(std::ostream &os, const complex &c);
};
#endif
