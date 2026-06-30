// Problem: Divide Two Integers
// Difficulty: Medium
// Link: https://leetcode.com/problems/divide-two-integers/
// Approach: Bit Manipulation
// Time Complexity: O(log² n)
// Space Complexity: O(1)

class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        long long dvd = abs((long long)dividend);
        long long dvs = abs((long long)divisor);

        long long ans = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while (dvd >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }

        if ((dividend < 0) ^ (divisor < 0)) {
            ans = -ans;
        }

        return (int)ans;
    }
};
