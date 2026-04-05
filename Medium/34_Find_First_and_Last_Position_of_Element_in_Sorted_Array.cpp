// Problem: Find First and Last Position of Element in Sorted Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
// Approach: Binary Search (First & Last Occurrence)
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        int firstIdx = -1, lastIdx = -1;

        // ---------- first index ----------
        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                firstIdx = mid;
                end = mid - 1;
            } 
            else if (nums[mid] > target) {
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }

        // ---------- last index ----------
        start = 0, end = nums.size() - 1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                lastIdx = mid;
                start = mid + 1;
            } 
            else if (nums[mid] > target) {
                end = mid - 1;
            } 
            else {
                start = mid + 1;
            }
        }

        return {firstIdx, lastIdx};
    }
};
