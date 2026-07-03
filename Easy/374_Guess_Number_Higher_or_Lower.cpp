// Problem: Guess Number Higher or Lower
// Difficulty: Easy
// Link: https://leetcode.com/problems/guess-number-higher-or-lower/
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

/** 
 * Forward declaration of guess API.
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {

        long long left = 1;
        long long right = n;

        while (left <= right) {

            long long mid =
                left + (right - left) / 2;

            int res = guess(mid);

            if (res == 0) {
                return mid;
            }
            else if (res == -1) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return -1;
    }
};
