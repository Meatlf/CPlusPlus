#include"move.h"

// class Move
// {
// private:
//     /* data */
//     double x;
//     double y;
// public:
//     Move(double a=0,double b=0);
//     void showmove() const;
//     Move add(const Move & m) const;
//     void reset(double a=0, double b=0);

//     ~Move();
// };

Move::Move(double a,double b)
{
    x=a;
    y=b;
}

Move::~Move()
{

}

void Move::showmove() const
{
    cout<<x<<endl<<y<<endl;
}

Move Move::add(const Move & m)
{
    x+=m.x;
    y+=m.y;
    return *this;
}

void Move::reset(double a, double b)
{
    x=a;
    y=b;
}