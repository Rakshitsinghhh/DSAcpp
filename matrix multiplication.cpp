#include<iostream>
using namespace std;

void martixprnt(int a[2][3])
{
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

}

void martixprnt1(int b[3][2])
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

}

void matrixPrintC(int c[2][2])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}



int main()
{
    int a[2][3];
    int b[3][2];
    int c[2][2];

    cout<<"enter element of 1st matrix";
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>a[i][j];
        }
    }

    cout<<"enter element of 2st matrix";
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<2;j++)
        {
            cin>>b[i][j];
        }
    }


    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            c[i][j] = 0;
            for(int k = 0; k < 3; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }



    cout<<"1st matrix"<<endl;
    martixprnt(a);

    cout<<"2st matrix"<<endl;
    martixprnt1(b);

    cout<<"final matrix"<<endl;
    matrixPrintC(c);




}