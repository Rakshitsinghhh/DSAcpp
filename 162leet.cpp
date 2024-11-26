class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 0) { 
            return -1; 
        }
        int maxVal = nums[0]; 
        int maxIndex = 0; 

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxVal) { 
                maxVal = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex; 
    }
};
