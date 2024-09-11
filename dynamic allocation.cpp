#include<iostream>
using namespace std;

int main()
{

    int a = 5;
    int **ptr = new int*[a];

    for(int  i=0;i<5;i++)
    {
        ptr[i]=new int[a];

    }


    for(int  i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cin>>ptr[i][j];            
        }

    }


    for(int  i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<ptr[i][j];            
        }

    }


    for(int  i=0;i<5;i++)
    {
        delete []ptr[i];

    }    

    delete []ptr;
} 