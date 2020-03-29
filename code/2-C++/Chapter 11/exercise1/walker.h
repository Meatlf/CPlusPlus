// mytime1.h -- Time class before operator overloading
#ifndef MYTIME1_H_
#define MYTIME1_H_

class Walker
{
private:
    int distance_;
    int step_;
public:
    Walker();
    Walker(int distance, int step);
    void AddStep(int step);
    void Reset(int distance = 0, int step = 0);
    Walker operator+(const Walker & t) const;
    void Show() const;
};
#endif
