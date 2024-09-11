#include<iostream>
#include<string>
using namespace std;

class Solution {
private:
    void solve(string str,string output,int index ,vector<string>& ans)
    {   

        if(index>=str.length())
        {   
            ans.push_back(output);
            return;
        }


        //exclusion

        solve(str,output,index+1,ans);

        //incl
        char ele=str[i];
        output.push_back(ele);
        solve(nums,output,index+1,ans);

    }
public:
    vector<string> subsequence(string str) {

        vector<string> > ans;
        string output="";
        int index=0;
        solve(str,output,index,ans);
        return ans;



        
    }
};