#include<iostream>
using namespace std;



int partitionfnc(int a[] , int s, int e)
{

    int cnt=0;
    int pivot=a[s];
    for(int i=s+1;i<e;i++)
    {
        if(a[i]<=pivot){
            cnt++;

        }
        

    }
    //place pivot
    int pvtindex=s+cnt;
    swap(a[pvtindex],a[s]);



    //left 
    int i=s;
    int j=e;

    while(i<pvtindex && j> pvtindex)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        
        if(i<pvtindex && j> pvtindex)
        {
            swap(a[i++],a[j--]);
        }

    }
    return pvtindex;
}


void quicksort(int a[] , int s , int e )
{
    if(s>=e)
    {
        return;

    }
    //partition
    int p=partitionfnc(a,s,e);
    


    //left sort
    quicksort(a,s,p-1);


    //right sort

    quicksort(a,p+1,e);


}

int main()
{
    int a[5]={3,2,4,1,5};
    int n=5;

    quicksort(a,0,n-1);

    for (int i=0;i<n;i++)
    {

        cout<<a[i]<<" ";
    }



}