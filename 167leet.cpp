class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> f;
        for (int i = 0; i < numbers.size(); i++) {
            for (int j = i + 1; j < numbers.size(); j++) {
                if (numbers[i] + numbers[j] == target) {
                    f.push_back(1+i);
                    f.push_back(1+j);
                    return f; 
                }
            }
        }
        return f;
    }
};
