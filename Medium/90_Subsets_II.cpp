// Problem: Subsets II
// Difficulty: Medium
// Approach: Backtracking + Sorting
// Time Complexity: O(n * 2^n)
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

        // Skip duplicates
        int idx = i + 1;
        while (idx < nums.size() &&
               nums[idx] == nums[idx - 1]) {
            idx++;
        }

        // Exclude current element
        getSubset(nums, ans, idx, allSubsets);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;
        vector<int> ans;

        getSubset(nums, ans, 0, allSubsets);

        return allSubsets;
    }
};
