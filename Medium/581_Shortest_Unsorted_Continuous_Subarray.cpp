// Problem: Shortest Unsorted Continuous Subarray
// Difficulty: Medium
// Approach: Two Passes (Track Running Max and Min)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxNum = INT_MIN;
        int minNum = INT_MAX;

        int left = -1;
        int right = -1;

        for (int i = 0; i < n; i++) {
            maxNum = max(nums[i], maxNum);

            if (nums[i] < maxNum) {
                right = i;
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            minNum = min(nums[i], minNum);

            if (nums[i] > minNum) {
                left = i;
            }
        }

        if (right == -1) {
            return 0;
        }

        return right - left + 1;
    }
};
