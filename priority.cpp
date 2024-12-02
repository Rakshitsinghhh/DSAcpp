#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter number of processes";
    cin>>n;

    int process[n],wt[n],bt[n],tat[n],priority[n];

    for(int i=0;i<n;i++)
    {
        process[i]=i+1;
        cout<<"enter burst time and priority";
        cin>>bt[i]>>priority[i];

    }

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(priority[i]>priority[j])
            {
                swap(priority[i],priority[j]);
                swap(bt[i],bt[j]);

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
        tat[i]=bt[i]+wt[i];

    }

    cout << "\nProcess\tBurst Time\tpriority Time \tWaiting Time\tTurnaround Time" << endl; 
    for(int i=0;i<n;i++)
    {
        cout<<"p"<<process[i]<<"\t"<<bt[i]<<"\t\t"<<priority[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    return 0;
}