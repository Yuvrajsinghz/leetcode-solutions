// Problem: Subsets
// Difficulty: Medium
// Approach: Backtracking (Include / Exclude)
/// Time Complexity: O(n * 2^n)
// Space Complexity: O(n)

class Solution {
public:
    void getSubset(vector<int>& nums,
                   vector<int>& ans,
                   int i,
                   vector<vector<int>>& allSubsets) {

        if (i == nums.size()) {
            allSubsets.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(nums[i]);
        getSubset(nums, ans, i + 1, allSubsets);

        ans.pop_back();

        // Exclude current element
        getSubset(nums, ans, i + 1, allSubsets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> allSubsets;
        vector<int> ans;

        getSubset(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};
