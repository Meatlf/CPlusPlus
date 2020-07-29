// studentc.cpp -- Student class using containment
#include <iostream>
#include "winec.h"

//public methods
void Wine::GetBottles()
{
    int y, b;
    std::cout << "Enter " << label << " data for " << years << " year(s)" << std::endl;
    for (int i = 0; i < years; ++i)
    {
        std::cout << "Enter year: ";
        std::cin >> y;
        data.first()[i] = y;
        std::cout << "Enter bottles for that year: ";
        std::cin >> b;
        data.second()[i] = b;
    }
}

int Wine::sum()
{
    return data.second().sum();
}

void Wine::Show() const
{
    std::cout << "Wine: " << label << std::endl;
    std::cout << "Year "
              << "  Bottles" << std::endl;
    for (int i = 0; i < years; ++i)
    {
        std::cout << data.first()[i] << " ";
        std::cout << data.second()[i] << std::endl;
    }
}
