// Problem: Maximum Subarray
// Difficulty: Medium
// Link: https://leetcode.com/problems/maximum-subarray/
// Approach: Kadane's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0, maxSum = INT_MIN;

        for (int value : nums) {
            currentSum += value;
            maxSum = max(maxSum, currentSum);

            if (currentSum < 0) {
                currentSum = 0;
            }
        }

        return maxSum;
    }
};
