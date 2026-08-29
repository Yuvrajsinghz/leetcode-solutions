// Problem: Lexicographically Smallest Array by Swapping Elements
// Difficulty: Medium
// Link: https://leetcode.com/problems/lexicographically-smallest-array-by-swapping-elements/
// Approach: Sort indices by value, group elements whose adjacent value difference is <= limit, then assign sorted values to sorted original positions.
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();

        vector<int> idx(n);

        // Store original indices
        iota(idx.begin(), idx.end(), 0);

        // Sort indices according to their values
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });

        vector<int> ans(n);

        int i = 0;

        while (i < n) {
            int j = i + 1;

            // Find all values belonging to the same group
            while (j < n &&
                   nums[idx[j]] - nums[idx[j - 1]] <= limit) {
                j++;
            }

            // Get original indices of this group
            vector<int> positions(idx.begin() + i, idx.begin() + j);

            // Smaller index should get smaller value
            sort(positions.begin(), positions.end());

            // Put sorted values into sorted original positions
            for (int k = i; k < j; k++) {
                ans[positions[k - i]] = nums[idx[k]];
            }

            i = j;
        }

        return ans;
    }
};