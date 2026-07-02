// Problem: Maximum Multiplication Score
// Difficulty: Medium
// Link: https://leetcode.com/problems/maximum-multiplication-score/
// Approach: Space Optimized DP
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long maxScore(vector<int>& a, vector<int>& b) {

        vector<long long> dp(5, LLONG_MIN);
        dp[0] = 0;

        for (int x : b) {

            for (int k = 4; k >= 1; k--) {

                if (dp[k - 1] != LLONG_MIN) {

                    dp[k] = max(
                        dp[k],
                        dp[k - 1] +
                        1LL * a[k - 1] * x
                    );
                }
            }
        }

        return dp[4];
    }
};
