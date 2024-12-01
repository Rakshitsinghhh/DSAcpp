struct VectorHash {
    template <typename T>
    size_t operator()(const vector<T>& vec) const {
        size_t hash = 0;
        for (const T& val : vec) {
            hash ^= hash * 31 + std::hash<T>{}(val);
        }
        return hash;
    }
};

class Solution {
private:
    void solve(unordered_set<vector<int>, VectorHash>& ans, vector<int>& nums, int index) {
        if (index == nums.size()) {
            ans.insert(nums);
            return;
        }

        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);  // Swap to create a new permutation
            solve(ans, nums, index + 1);  // Recurse with next index
            swap(nums[index], nums[i]);  // Backtrack
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<vector<int>, VectorHash> ans;
        solve(ans, nums, 0);
        
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};