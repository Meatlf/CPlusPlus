#include"sales.h"

using namespace std;
using namespace SALES;

int main()
{
    const double ar[QUARTERS] = {1,2,3,4};
    int n = QUARTERS;

    Sales s0(ar,n);

    s0.showSales();

    Sales s1;
    s1.showSales();

    return 0;
}