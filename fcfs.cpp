#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter number of precesses";
    cin>>n;

    int processes[n];
    int bt[n];
    int wt[n];
    int tat[n];


    for(int i=0;i<n;i++)
    {
        cout<<"enter burst time of process"<<i+1<<" "<<endl;
        cin>>bt[i];

    }

    wt[0]=0;

    for(int i=1;i<n;i++)
    {
        wt[i]=bt[i-1]+wt[i-1];
    }

    for(int i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
    }


    cout << "\nProcess\tBurst Time\tWaiting Time\tTurnaround Time" << endl; 
    for(int i=0;i<n;i++)
    {
        cout<<"p"<<i+1<<"\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    return 0;

}