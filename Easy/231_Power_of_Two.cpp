// Problem: Power of Two
// Difficulty: Easy
// Link: https://leetcode.com/problems/power-of-two/
// Approach: Bit Manipulation
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n > 0 && (n & (n - 1)) == 0);
    }
};
