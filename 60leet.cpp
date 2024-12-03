#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    void per(string s, int index, set<string> &final) {
        if (index == s.size()) {
            final.insert(s);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            swap(s[index], s[i]);      
            per(s, index + 1, final);  
            swap(s[index], s[i]);
        }
    }

public:
    string getPermutation(int n, int k) {
        string s;
        for (int i = 1; i <= n; i++) {
            s += to_string(i);
        }

        set<string> final;
        per(s, 0, final);

        auto it = final.begin();
        advance(it, k - 1);
        return *it;
    }
};
