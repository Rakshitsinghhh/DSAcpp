class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string f;
        int count = 0;
        int spaceIndex = 0;

        for (int i = 0; i < s.length(); i++) {
            if (spaceIndex < spaces.size() && count == spaces[spaceIndex]) {
                f += " ";
                spaceIndex++; 
            }
            f += s[i]; 
            count++;
        }

        return f;
    }
};
