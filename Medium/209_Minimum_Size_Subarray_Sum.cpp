// Problem: Minimum Size Subarray Sum
// Difficulty: Medium
// Approach: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int right = 0;
        int left = 0;
        int minLen = INT_MAX;
        int size = arr.size();
        int sum = 0;

        while (right < size) {
            sum += arr[right++];

            while (sum >= target) {
                minLen = min(minLen, right - left);
                sum -= arr[left];
                left++;
            }
        }

        return (minLen == INT_MAX) ? 0 : minLen;
    }
};
