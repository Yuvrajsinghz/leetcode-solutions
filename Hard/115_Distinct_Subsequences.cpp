// Problem: 115. Distinct Subsequences
// Difficulty: Hard
// Link: https://leetcode.com/problems/distinct-subsequences/
// Approach: Use Dynamic Programming to count the number of distinct subsequences.
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)
class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size();
        int n = t.size();
        
        vector<vector<long long>> dp(
            m + 1, vector<long long>(n + 1, 0)
        );
        
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s[i] == t[j]) {
                    long long choose = dp[i + 1][j + 1];
                    long long skip = dp[i + 1][j];
                    
                    if (choose > INT_MAX - skip)
                        dp[i][j] = INT_MAX;
                    else
                        dp[i][j] = choose + skip;
                }
                else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};