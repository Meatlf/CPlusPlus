// exercise05.cpp --
#include <iostream>
#include <string>

using namespace std;

const string months[12] = {"January", "February", "March", "April",
                           "May", "June", "July", "August",
                           "September", "October", "November", "December"};

int main()
{
    float sales[1000];
    int i = 0;
    float sum = 0.0;
    while (months[i] != "\0")
    {
        cout << "请输入" << months[i] << "月的销售额： ";
        cin >> sales[i];
        sum += sales[i];
        i++;
    }

    i = 0;
    cout << "\n销售额的报告："<<endl;
    while (months[i] != "\0")
    {
        cout << months[i] << "月的销售额： "<<sales[i]<<endl;
        i++;
    }
    cout << "这一年的总销售额为： " << sum << endl;
    // std::cin.get();
    return 0;
}