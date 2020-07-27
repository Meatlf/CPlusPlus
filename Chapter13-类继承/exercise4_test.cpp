// usedma.cpp -- inheritance, friends, and DMA
// compile with dma.cpp
#include <iostream>
#include "class_4.h"

int main()
{
    using std::cout;
    using std::endl;

    Port port1("BLD", "tawny", 10);
    cout << port1 << endl;
    port1 += 10;
    cout << port1 << endl;
    Port port2 = port1;
    cout << port2 << endl;
    cout << "酒的瓶数为：" << port2.BottleCount() << endl;
    return 0;
}
