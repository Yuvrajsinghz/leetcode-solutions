// Problem: Stone Game II
// Difficulty: Medium
// Approach: DP + Minimax + Suffix Sum
// Time Complexity: O(n³)
// Space Complexity: O(n²)

class Solution {
public:
    int n;
    vector<int> suf;
    int dp[101][101];

    int solve(int i, int M) {

        if (i >= n) {
            return 0;
        }

        if (2 * M >= n - i) {
            return suf[i];
        }

        if (dp[i][M] != -1) {
            return dp[i][M];
        }

        int ans = 0;

        for (int x = 1; x <= 2 * M; x++) {
            ans = max(
                ans,
                suf[i] - solve(i + x, max(M, x))
            );
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {

        n = piles.size();

        suf.assign(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + piles[i];
        }

        memset(dp, -1, sizeof(dp));

        return solve(0, 1);
    }
};
