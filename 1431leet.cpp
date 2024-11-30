class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<int> q;
        vector<bool> result;

        for (int ele : candies) {
            q.push_back(ele + extraCandies);
        }

        int max=candies[0];
        for (int ele : candies) {
            if (ele > max) {
                max = ele;
            }
        }

        for(int ele : q)
        {
            if(ele >=max)
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
        return result;
    }
};