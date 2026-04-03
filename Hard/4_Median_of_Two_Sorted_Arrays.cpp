// Problem: Median of Two Sorted Arrays
// Difficulty: Hard
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Approach: Binary Search on Partition
// Time Complexity: O(log(min(n, m)))
// Space Complexity: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        // ensure A is smaller array
        if (A.size() > B.size()) {
            return findMedianSortedArrays(B, A);
        }

        int n = A.size();
        int m = B.size();

        int low = 0, high = n;

        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (n + m + 1) / 2 - cut1;

            int left1 = (cut1 == 0) ? INT_MIN : A[cut1 - 1];
            int left2 = (cut2 == 0) ? INT_MIN : B[cut2 - 1];

            int right1 = (cut1 == n) ? INT_MAX : A[cut1];
            int right2 = (cut2 == m) ? INT_MAX : B[cut2];

            // correct partition
            if (left1 <= right2 && left2 <= right1) {
                // odd length
                if ((n + m) % 2 == 1) {
                    return max(left1, left2);
                } 
                // even length
                else {
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
                }
            }
            else if (left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }

        return 0.0;
    }
};
