#include "golf.h"

int main()
{
    golf ann[3];
    for (int i = 0; i < 3; i++)
        ann[i].setgolf("Ann Birdfree", 24);

    for (int i = 0; i < 3; i++)
        ann[i].showgolf();
    return 0;
}