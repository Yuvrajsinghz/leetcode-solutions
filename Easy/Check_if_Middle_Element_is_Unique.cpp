// Problem: Check if Middle Element is Unique
// Difficulty: Easy
// Approach: Count Frequency of Middle Element
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        int midEle = nums[n / 2];
        int count = 0;

        for (int num : nums) {
            if (midEle == num) {
                count++;
            }
        }

        return count == 1;
    }
};
