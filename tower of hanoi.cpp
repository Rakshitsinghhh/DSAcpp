#include<iostream>
using namespace std;


void toh(int n, char begin ,char end ,char aux)
{
    if(n==1)
    {
        cout<<"move disk 1 from "<< begin <<" to "<< end << endl;
        return;

    }
    toh(n-1,begin,aux,end);

    cout<<"move disk "<<n <<" from "<< begin <<" to "<< aux << endl;

    toh(n-1,aux,end,begin);







}

int main()
{

    int n;
    cout<<"how many disks?";
    cin>>n;
    toh(n,'A','C','B');
    return 0;
}