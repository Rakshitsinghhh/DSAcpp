//selectiom sort
#include<iostream>
using namespace std;

int main()
{
    int a[5]={2,3,1,5,4};
    int minindex=0;
    for(int i=0;i<=5;i++)
    {
        minindex=i;
        for(int j=i+1;j<5;j++)
        {

            if(a[minindex]>a[j])
                minindex=j;

        }
        swap(a[minindex],a[i]);




    }
    for(int i=0;i<5;i++)
    {

        cout<<a[i];
    }



}
