// Problem: Valid Perfect Square
// Difficulty: Easy
// Link: https://leetcode.com/problems/valid-perfect-square/
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPerfectSquare(int num) {

        long long start = 1;
        long long end = num;

        while (start <= end) {

            long long mid =
                start + (end - start) / 2;

            long long square = mid * mid;

            if (square == num) {
                return true;
            }
            else if (square < num) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return false;
    }
};
