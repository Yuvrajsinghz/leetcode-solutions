// Problem: Majority Element
// Difficulty: Easy
// Link: https://leetcode.com/problems/majority-element/
// Approach: Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, candidate = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }

            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }

        return candidate;
    }
};
