// Problem: Find Minimum in Rotated Sorted Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // array is rotated
            if (arr[mid] > arr[end]) {
                start = mid + 1;
            } else {
                end = mid;
            }
        }

        return arr[start];
    }
};
