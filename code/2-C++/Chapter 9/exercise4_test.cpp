#include"sales.h"

using namespace std;
using namespace SALES;

int main()
{
    Sales s;
    const double ar[QUARTERS] = {1,2,3,4};
    int n = QUARTERS;

    setSales(s, ar, n);
    showSales(s);

    setSales(s);
    showSales(s);

    return 0;
}