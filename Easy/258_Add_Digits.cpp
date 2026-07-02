// Problem: Add Digits
// Difficulty: Easy
// Link: https://leetcode.com/problems/add-digits/
// Approach: Digital Root Mathematics
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int addDigits(int num) {

        if (num == 0) {
            return 0;
        }

        return 1 + (num - 1) % 9;
    }
};
