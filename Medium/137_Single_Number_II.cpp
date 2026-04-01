// Problem: Single Number II
// Difficulty: Medium
// Link: https://leetcode.com/problems/single-number-ii/
// Approach: Bit Manipulation (Bit Counting)
// Time Complexity: O(32 * n) ≈ O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (int bit = 0; bit < 32; bit++) {
            int count = 0;

            for (int num : nums) {
                if ((num >> bit) & 1) {
                    count++;
                }
            }

            if (count % 3 != 0) {
                ans |= (1 << bit);
            }
        }

        return ans;
    }
};
