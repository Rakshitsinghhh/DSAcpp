//bubble sort
#include<iostream>
using namespace std;

int main()
{
    int a[5]={2,3,1,5,4};
    for (int i=0;i<5;i++)
    {
        for(int j=0;j<5-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }


    }
    
    
    for(int i=1;i<=5;i++)
    {
        cout<<a[i];
    }


}