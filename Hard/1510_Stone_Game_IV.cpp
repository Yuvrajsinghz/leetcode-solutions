// Problem: Stone Game IV
// Difficulty: Hard
// Approach: Dynamic Programming
// Time Complexity: O(n * sqrt(n))
// Space Complexity: O(n)

class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {

                if (!dp[i - j * j]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
