#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> a={1,2,4,5};
    int max=0;

    for(int i=1;i<a.size();i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }

    for(int i=1;i<=max;i++)

        if (find(a.begin(), a.end(), i) == a.end()) 
        {
            cout << "Missing number: " << i << endl; 
        }
}
