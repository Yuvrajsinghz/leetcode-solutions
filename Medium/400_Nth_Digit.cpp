// Problem: Nth Digit
// Difficulty: Medium
// Approach: Math
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findNthDigit(int n) {
        long long digits = 1;
        long long count = 9;
        long long start = 1;

        while (n > digits * count) {
            n -= digits * count;
            digits++;
            count *= 10;
            start *= 10;
        }

        long long number = start + (n - 1) / digits;

        string s = to_string(number);

        return s[(n - 1) % digits] - '0';
    }
};
