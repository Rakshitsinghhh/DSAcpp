#include<iostream>
#include<string>
using namespace std;

int main()
{
    int data = 11;
    string bin;
    
    while(data > 0)
    {
        int remainder = data % 2;
        bin = to_string(remainder) + bin;
        data = data / 2;
    }

    int count=0;
    for(int i=0;i<bin.length();i++)
    {
        if(bin[i]=='1')
        {
            count++;
        }
    }
    cout<<count;
}
