// Problem: Merge Sorted Array
// Difficulty: Easy
// Link: https://leetcode.com/problems/merge-sorted-array/
// Approach: Two Pointers (From End)
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m + n;

        while (n > 0) {
            if (m > 0 && nums1[m - 1] >= nums2[n - 1]) {
                nums1[j - 1] = nums1[m - 1];
                m--;
            } else {
                nums1[j - 1] = nums2[n - 1];
                n--;
            }
            j--;
        }
    }
};
