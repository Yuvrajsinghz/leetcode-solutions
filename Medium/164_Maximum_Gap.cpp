// Problem: Maximum Gap
// Difficulty: Medium
// Approach: Sort and Find Maximum Adjacent Difference
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int maximumGap(vector<int>& nums) {

        // Base case
        if (nums.size() < 2) {
            return 0;
        }

        int mxAns = 0;

        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            mxAns = max(mxAns, nums[i] - nums[i - 1]);
        }

        return mxAns;
    }
};
