// Problem: Integer Replacement
// Difficulty: Medium
// Approach: Greedy + Bit Manipulation
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int integerReplacement(int num) {
        long long n = num;
        int steps = 0;

        while (n != 1) {
            if (n % 2 == 0) {
                n /= 2;
            }
            else {
                if (n == 3 || (n & 3) == 1) {
                    n -= 1;
                }
                else {
                    n += 1;
                }
            }
            steps++;
        }

        return steps;
    }
};
