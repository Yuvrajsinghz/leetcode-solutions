// Problem: First Bad Version
// Difficulty: Easy
// Link: https://leetcode.com/problems/first-bad-version/
// Approach: Binary Search (First True)
// Time Complexity: O(log n)
// Space Complexity: O(1)

/* The isBadVersion API is defined for you.
   bool isBadVersion(int version); */

class Solution {
public:
    int firstBadVersion(int n) {

        int low = 1;
        int high = n;

        while (low < high) {

            int mid =
                low + (high - low) / 2;

            if (isBadVersion(mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
