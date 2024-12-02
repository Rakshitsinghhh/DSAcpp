#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter number of processes";
    cin>>n;
    int process[n],bt[n],wt[n],tat[n];

    for(int i=0;i<n;i++)
    {
        process[i]=i+1;

    }

    cout<<"enter burst time";
    for(int i=0;i<n;i++)
    {
        cout<<"enter burst time of"<<i+1<<endl;
        cin>>bt[i];
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                swap(bt[j],bt[j+1]);
                swap(process[j],process[j+1]);
            }
        }

    }
    wt[0]=0;
    for(int i=1;i<n;i++)
    {
        wt[i]=wt[i-1]+bt[i-1];

    }

    for(int i=0;i<n;i++)
    {
        tat[i]=wt[i]+bt[i];
    }

    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" << endl; 
    for(int i=0;i<n;i++)
    {
        cout<<"p"<<process[i]<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    return 0;

}