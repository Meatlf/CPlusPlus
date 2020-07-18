// exercise06.cpp --
#include <iostream>
#include <string>

using namespace std;

const int yearsNumber = 3;
const int monthsNumber = 12;
const string months[monthsNumber] = {"January", "February", "March", "April",
                                     "May", "June", "July", "August",
                                     "September", "October", "November", "December"};

int main()
{
    float sales[yearsNumber][monthsNumber];
    int i, j;
    float sum = 0.0;

    for (j = 0; j < yearsNumber; j++)
    {
        for (i = 0; i < monthsNumber; i++)
        {
            cout << "请输入第" << j + 1 << "年" << months[i] << "月的销售额： ";
            cin >> sales[j][i];
            sum += sales[j][i];
        }
        cout << "\n";
    }

    cout << "销售额的报告：" << endl;
    for (j = 0; j < yearsNumber; j++)
    {
        for (i = 0; i < monthsNumber; i++)
        {
            cout << "第" << j + 1 << "年" << months[i] << "月的销售额： "
                 << sales[j][i] << "\n";
        }
        cout << "\n";
    }
    cout << "这" << yearsNumber << "年的总销售额为： " << sum << endl;
    // std::cin.get();
    return 0;
}