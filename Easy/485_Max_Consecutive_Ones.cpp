// Problem: Max Consecutive Ones
// Difficulty: Easy
// Approach: Linear Scan
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                count++;
            } 
            else {
                maxCount = max(maxCount, count);
                count = 0;
            }
        }

        maxCount = max(maxCount, count);

        return maxCount;
    }
};
