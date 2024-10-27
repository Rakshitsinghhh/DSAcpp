#include<iostream>
#include<cmath>
using namespace std;




void worker(int *p,int* p1)
{
    int sum;
    int dif;
    sum=*p+*p1;
    dif=*p-*p1;
    int pos=abs(dif);
    *p=sum;
    *p1=pos;


}

int main()
{
    int a;
    int b;
    cin>>a;
    cin>>b;
    worker(&a,&b);
    cout<<a<<endl<<b;


}