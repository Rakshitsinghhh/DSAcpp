#include<iostream>
#include<vector>
using namespace std;



void arrmaker(int n,int q)
{

    vector<vector<int>> arr(n);

    for(int i=0;i<n;i++)
    {
        int size;
        cin>>size;
        vector<int> a(size);

        for(int j=0;j<size;j++)
        {
            cin>>a[j];
        }

        arr[i]=a;

        // for(int k=0;k<size;k++)
        // {
        //     cout<<a[k]<<" ";
        // }
        // cout<<endl;

    }

    for(int l=0;l<q;l++)
    {
        int arn;
        cin>>arn;
        int ele;
        cin>>ele;
        int index=0;
        if(arn>=0 && arn<=n && ele>=0 && ele < arr[arn].size())
        {
            cout<<arr[arn][ele]<<endl;
        }
        else
        {
            cout<<"elleeee";
        }
    }

}


int main()
{
    int n;
    int q;
    cin>>n>>q;
    arrmaker(n,q);
    return 0;



}