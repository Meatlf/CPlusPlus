#include"move.h"

using namespace std;

int main()
{
    Move mover0 = Move();
    Move mover1(3,4);

    mover0 = mover0.add(mover1);

    mover0.showmove();
    
    return 0;
}