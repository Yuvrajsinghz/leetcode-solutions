// Problem: Stone Game VIII
// Difficulty: Hard
// Link: https://leetcode.com/problems/stone-game-viii/
// Approach: Prefix Sum + Dynamic Programming
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();

        vector<int> prefix(n);
        prefix[0] = stones[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + stones[i];
        }

        int dp = prefix[n - 1];

        for (int i = n - 2; i >= 1; i--) {
            dp = max(dp, prefix[i] - dp);
        }

        return dp;
    }
};