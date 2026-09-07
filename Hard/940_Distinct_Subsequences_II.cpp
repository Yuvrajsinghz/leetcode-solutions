// Problem: Distinct Subsequences II
// Difficulty: Hard
// Link: https://leetcode.com/problems/distinct-subsequences-ii/
// Approach: Dynamic Programming with last occurrence tracking
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int distinctSubseqII(string s) {
        const long long MOD = 1000000007;

        long long dp = 1;
        vector<long long> last(26, 0);

        for (char c : s) {
            int index = c - 'a';

            long long oldDp = dp;

            dp = (2 * dp - last[index] + MOD) % MOD;

            last[index] = oldDp;
        }

        return (dp - 1 + MOD) % MOD;
    }
};