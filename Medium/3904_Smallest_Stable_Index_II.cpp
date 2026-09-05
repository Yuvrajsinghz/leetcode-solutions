// Problem: Smallest Stable Index II
// Difficulty: Medium 
// Approach: Prefix Maximum + Suffix Minimum
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> right(n);
        right[n - 1] = nums[n - 1];

        // Suffix minimum
        for (int i = n - 2; i >= 0; i--) {
            right[i] = min(right[i + 1], nums[i]);
        }

        int left = 0;

        // Prefix maximum
        for (int i = 0; i < n; i++) {
            left = max(left, nums[i]);

            if (left - right[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};