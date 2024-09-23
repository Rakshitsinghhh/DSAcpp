#include<iostream>
using namespace std;
//bin search      done
//linear search   done
//bubble sort     done
//selection sort  done
//insertion sort  
//merge sort
//quick sort
//stack
//pointer

/*
int binarySearch(int a[],int key,int size)
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
        if(key>a[mid])
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
        mid=(start+end)/2;
    }
    return -1;
}




int main()
{
    int a[5]={1,2,3,4,5};
    int key=3;
    int n=5;

    int ans=binarySearch(a,key,n);
    if(ans!=-1)
    {
        cout<<"element is found at "<<ans<<endl;
    }
    else
    {
        cout<<"element is found";
    }
    return 0;


}

*/




/*
void linearsearch(int a[], int key)
{
    for(int i=0;i<5;i++)
    {
        if(a[i]==key)
        {
            cout<<i;
        }
    }
}

int main()
{
    int key=4;
    int a[5]={1,2,3,4,5};

    linearsearch(a,key);

}
*/

/*
int main()
{
    int a[5]={3,2,5,4,1};

    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(a[j]>a[j+1])
            swap(a[j],a[j+1]);
        }


    }


    for(int i=1;i<=5;i++)
    {
        cout<<a[i];
    }

}


*/

/*
int main()
{
    int a[5]={3,2,5,4,1};

    for (int i=0;i<5;i++)
    {
        int min;
        min=i;
        for(int j=i+1;j<5;j++)
        {
            if(a[min]>a[j])
            swap(a[min],a[j]);
        }
    }



    for(int i=0;i<5;i++)
    {
        cout<<a[i];
    }
}

*/

int main()
{
    int a[5]={4,3,1,2,5};

    for(int i=0;i<5;i++)
    {
        int j=i;
        while(j>0 && a[j-1]>a[j])
        {
            int temp;
            temp=a[j-1];
            a[j-1]=a[j];
            a[j]=temp;
            j--;
            
        }
        
        
    }

    for(int i=0;i<5;i++)
    {
        cout<<a[i]<<endl;
    }
}


