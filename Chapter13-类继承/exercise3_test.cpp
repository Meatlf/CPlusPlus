// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "dma_2.h"

int main()
{
    using std::cout;
    using std::endl;

    ABC *pABC[3];

    pABC[0] = new baseDMA("Portabelly", 8);
    pABC[1] = new lacksDMA("red", "Blimpo", 4);
    pABC[2] = new hasDMA("Mercator", "Buffalo Keys", 5);
    cout << "Displaying baseDMA object:\n";
    cout << *pABC[0] << endl;
    (*pABC[0]).View();
    cout << *pABC[1] << endl;
    (*pABC[1]).View();
    cout << *pABC[2] << endl;
    (*pABC[2]).View();
    return 0;
}
