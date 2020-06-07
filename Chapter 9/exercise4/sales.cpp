#include"sales.h"

namespace SALES
{
    void setSales(Sales & s, const double ar[], int n)
    {
        s.max = ar[0];
        s.min = ar[0];
        s.sales[0]=ar[0];
        s.average=0;
        double sum=ar[0];
   
        for(int i=1;i<n;i++)
        {
            s.sales[i]=ar[i];
            sum+=ar[i];
            if(ar[i]>s.max)
                s.max=ar[i];
            if(ar[i]<s.max)
                s.min=ar[i];
        }
        s.average=sum/n;
    }

    void setSales(Sales & s)
    {
        double sum;
       
        cout<<"Please input 4 number:"<<endl;

        cin>>s.sales[0];
        sum=s.sales[0];
        s.max=s.sales[0];
        s.min=s.sales[0];

        for(int i=1;i<QUARTERS;i++)
        {
            cin>>s.sales[i];
            sum+=s.sales[i];
            if(s.sales[i]>s.max)
                s.max=s.sales[i];
            if(s.sales[i]<s.min)
                s.min=s.sales[i];
        }
        s.average=sum/QUARTERS;
    }

    void showSales(const Sales & s)
    {
        cout << "The array is " << s.sales[0] << " " <<s.sales[1]<<" "<<s.sales[2]<<" "<<s.sales[3] << endl
            <<"The array average is "<< s.average << endl << "The maximum in the array is " << s.max << endl
            <<"The maximum in the array is " << s.min<<endl;
    }
}
