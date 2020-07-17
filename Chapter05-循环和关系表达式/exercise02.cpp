// exercise02.cpp --
#include <iostream>
#include <string>
#include <array>

using namespace std;

const int ArSize = 100; // example of external declaration
int main()
{
    array<long double, ArSize + 1> factorials;
    factorials[1] = factorials[0] = 1L;
    for (int i = 2; i <= ArSize; i++)
        factorials[i] = (long double)i * factorials[i - 1];
    std::cout << ArSize << "! = " << factorials[ArSize] << std::endl;
    // std::cin.get();
    return 0;
}