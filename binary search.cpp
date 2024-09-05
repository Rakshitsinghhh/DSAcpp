#include<iostream>
using namespace std;



int bs(int a[6],int key,int size)
{
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;

    while(start<=end)
    {
        if(key==a[mid])
        {
            return mid;
        }
        if(key > a[mid])
        {
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=(start+end)/2;



    }
    return -1;

}

int main()
{
    int a[6]={1,2,2,3,4,5};
    int ans=bs(a,2,6);
    cout<<"postiton of element is"<<ans;



}