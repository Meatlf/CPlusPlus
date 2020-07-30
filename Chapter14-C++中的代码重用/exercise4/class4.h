// Class4.h  --
#ifndef Class4_H_
#define Class4_H_

#include <string>

class Person // an abstract base Person
{
private:
    std::string _firstname;
    std::string _lastname;

public:
    Person() : _firstname("no first name"), _lastname("no last name") {}
    Person(const std::string &firstname, const std::string &lastname)
        : _firstname(firstname), _lastname(lastname) {}
    virtual ~Person() = 0; // pure virtual destructor
    virtual void Show() const;
};

class Gunslinger : public Person
{
private:
    int nickNumber;

public:
    Gunslinger() : Person(), nickNumber(0) {}
    Gunslinger(const std::string &firstname, const std::string &lastname, int p = 0)
        : Person(firstname, lastname), nickNumber(p) {}
    Gunslinger(const Person &wk, int p = 0)
        : Person(wk), nickNumber(p) {}
    void Show() const;
    double Draw() const;
};

class PokerPlayer : public Person
{
public:
    PokerPlayer() : Person() {}
    PokerPlayer(const std::string &firstname, const std::string &lastname)
        : Person(firstname, lastname) {}
    PokerPlayer(const Person &wk)
        : Person(wk) {}
    int Draw();
    void Show() const;
};

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    float Gdraw();
    int Cdraw();
    void Show() const;
};

#endif
