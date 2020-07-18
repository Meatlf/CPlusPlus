// exercise04.cpp --
#include <iostream>

using namespace std;

const float baseMoney = 100.00;

int main()
{
    float DaphneMoney = baseMoney, CleoMoney = baseMoney;
    int years = 0;

    while (DaphneMoney >= CleoMoney)
    {
        DaphneMoney += 0.1 * baseMoney;
        CleoMoney += 0.05 * CleoMoney;
        years++;
    }
    cout << "第" << years << "后，Cleo的投资价值才能超过Daphne的投资价值。"
         << "此时，Cleo共有" << CleoMoney << "美元。Daphne共有" << DaphneMoney << "美元。" << endl;
    // std::cin.get();
    return 0;
}