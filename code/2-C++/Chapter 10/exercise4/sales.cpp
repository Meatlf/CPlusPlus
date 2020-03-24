#include"sales.h"

namespace SALES
{
    using namespace std;

    Sales::Sales(const double ar[], int n)
    {
        max = ar[0];
        min = ar[0];
        sales[0]=ar[0];
        average=0;
        double sum=ar[0];
   
        for(int i=1;i<n;i++)
        {
            sales[i]=ar[i];
            sum+=ar[i];
            if(ar[i]>max)
                max=ar[i];
            if(ar[i]<max)
                min=ar[i];
        }
        average=sum/n;
    }

    Sales::Sales()
    {
        double sum;
       
        cout<<"Please input 4 number:"<<endl;

        cin>>sales[0];
        sum=sales[0];
        max=sales[0];
        min=sales[0];

        for(int i=1;i<QUARTERS;i++)
        {
            cin>>sales[i];
            sum+=sales[i];
            if(sales[i]>max)
                max=sales[i];
            if(sales[i]<min)
                min=sales[i];
        }
        average=sum/QUARTERS;
    }

    Sales::~Sales()
    {

    }

    void Sales::showSales()
    {
        cout << "The array is " << sales[0] << " " <<sales[1]<<" "<<sales[2]<<" "<<sales[3] << endl
            <<"The array average is "<< average << endl << "The maximum in the array is " << max << endl
            <<"The maximum in the array is " << min<<endl;
    }
}
