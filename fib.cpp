#include<iostream>
using namespace std;


int fibonaci(int a)
{
    if(a==1)
    {
        return 1;

    }
    if(a==0)
    {
        return 0;
    }

    int x=0;
    int y=1;
    int fib=0;
    for(int i=2;i<a;i++)
    {
        fib=x+y;
        x=y;
        y=fib;
    }
    return y;


}

int main()
{

    int till=20;
    int ans = fibonaci(till);
    cout<<ans;
    return 0;
}