// tabtenn0.h -- a table-tennis base class
#ifndef SALES_H_
#define SALES_H_
#include<iostream>
#include<cstring>


namespace SALES
{
    const int QUARTERS = 4;

    // struct Sales
    // {
    //     double sales[QUARTERS];
    //     double average;
    //     double max;
    //     double min;
    // };

    // void setSales(Sales & s, const double ar[], int n);

    // void setSales(Sales & s);

    // void showSales(const Sales & s);

    class Sales
    {
    private:
        /* data */
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    public:
        Sales();
        Sales(const double ar[], int n);

        void showSales();

        ~Sales();
    };    
}
#endif
