// Problem: Longest Subsequence With Non-Zero Bitwise XOR
// Difficulty: Medium
// Approach: XOR + Zero Count
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        int cntZero = 0;

        int n = nums.size();

        for (int x : nums) {
            xr ^= x;

            if (x == 0) {
                cntZero++;
            }
        }

        if (xr != 0) {
            return n;
        }

        return (cntZero == n) ? 0 : n - 1;
    }
};
