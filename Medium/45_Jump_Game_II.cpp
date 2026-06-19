// Problem: Jump Game II
// Difficulty: Medium
// Link: https://leetcode.com/problems/jump-game-ii/
// Approach: Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int jump(vector<int>& arr) {
        int totalJumps = 0;
        int currentJumpEnd = 0;
        int maxReachableIndex = 0;

        for (int i = 0; i < arr.size() - 1; i++) {
            maxReachableIndex = max(maxReachableIndex, i + arr[i]);

            if (i == currentJumpEnd) {
                totalJumps++;
                currentJumpEnd = maxReachableIndex;
            }
        }

        return totalJumps;
    }
};
