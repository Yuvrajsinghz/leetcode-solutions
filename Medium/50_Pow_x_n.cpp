// Problem: Pow(x, n)
// Difficulty: Medium
// Link: https://leetcode.com/problems/powx-n/
// Approach: Binary Exponentiation
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        double ans = 1;

        if (n < 0) {
            x = 1 / x;
            N = -N;
        }

        while (N > 0) {
            if (N & 1) {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }

        return ans;
    }
};
