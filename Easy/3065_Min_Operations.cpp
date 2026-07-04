// Problem: Minimum Operations to Make Array Sum Greater Than or Equal to K
// Difficulty: Easy
// Approach: Linear Scan
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;

        for (int num : nums) {
            if (num < k) {
                count++;
            }
        }

        return count;
    }
};
