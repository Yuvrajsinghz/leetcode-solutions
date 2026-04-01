// Problem: Single Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/single-number/
// Approach: Bit Manipulation (XOR)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for(int val : nums){
            ans ^= val;
        }

        return ans;
    }
};
