// Problem: Find Peak Element
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-peak-element/
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start = 0, end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] > arr[mid + 1]) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }

        return start;
    }
};
