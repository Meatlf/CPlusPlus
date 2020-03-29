// myWalker1.cpp  -- implementing Walker methods
#include <iostream>
#include "walker.h"

Walker::Walker()
{
    distance_ = step_ = 0;
}

Walker::Walker(int distance, int step )
{
    distance_ = distance;
    step_ = step;
}

void Walker::AddStep(int step)
{
    step_ += step;
}

void Walker::Reset(int distance, int step)
{
    distance_ = distance;
    step_ = step;
}

Walker Walker::operator+(const Walker & t) const
{
    Walker sum;
    sum.step_ = step_ + t.step_;
    sum.distance_ = distance_ + t.distance_ + sum.step_ / 60;
    return sum;
}

void Walker::Show() const
{
    std::cout << "Target distance_: " << distance_ << " step_ Size:" << step_ ;
}
