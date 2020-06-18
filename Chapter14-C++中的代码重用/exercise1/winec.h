// wine.h -- defining a Student class using containment
#ifndef WINE_H_
#define WINE_H_

#include <iostream>
#include <string>
#include <valarray>
class Student
{
private:
    typedef std::valarray<double> ArrayDb;
    std::string name; // contained object
    ArrayDb scores;   // contained object
    // private method for scores output
    std::ostream &arr_out(std::ostream &os) const;

public:
    Student() : name("Null Student"), scores() {}
    explicit Student(const std::string &s)
        : name(s), scores() {}
    explicit Student(int n) : name("Nully"), scores(n) {}
    Student(const std::string &s, int n)
        : name(s), scores(n) {}
    Student(const std::string &s, const ArrayDb &a)
        : name(s), scores(a) {}
    Student(const char *str, const double *pd, int n)
        : name(str), scores(pd, n) {}
    ~Student() {}
    double Average() const;
    const std::string &Name() const;
    double &operator[](int i);
    double operator[](int i) const;
    // friends
    // input
    friend std::istream &operator>>(std::istream &is,
                                    Student &stu); // 1 word
    friend std::istream &getline(std::istream &is,
                                 Student &stu); // 1 line
    // output
    friend std::ostream &operator<<(std::ostream &os,
                                    const Student &stu);
};

template <class T1, class T2>
class Pair
{
private:
    T1 a;
    T2 b;

public:
    T1 &first();
    T2 &second();
    T1 first() const { return a; }
    T2 second() const { return b; }
    Pair(const T1 &aval, const T2 &bval) : a(aval), b(bval) {}
    Pair() {}
};

template <class T1, class T2>
T1 &Pair<T1, T2>::first()
{
    return a;
}
template <class T1, class T2>
T2 &Pair<T1, T2>::second()
{
    return b;
}

class Wine
{
private:
    typedef std::valarray<int> ArrayInt;
    typedef Pair<ArrayInt, ArrayInt> PairArray;
    std::string name;
    PairArray information;

public:
    Wine();
    Wine(const char *l, int y, const int yr[], const int bot[]);
    Wine(const char *l, int y);
    void GetBottles();
    void Show();
    int Label();
    int sum();
};
#endif
