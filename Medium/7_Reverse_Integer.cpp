// Problem: Reverse Integer
// Difficulty: Medium
// Link: https://leetcode.com/problems/reverse-integer/
// Approach: Math (Digit Extraction & Overflow Check)
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int reverse(int x) {
        int reversedNumber = 0;

        while (x != 0) {
            int lastDigit = x % 10;
            x /= 10;

            if (reversedNumber > INT_MAX / 10 || reversedNumber < INT_MIN / 10) {
                return 0;
            }

            reversedNumber = reversedNumber * 10 + lastDigit;
        }

        return reversedNumber;
    }
};