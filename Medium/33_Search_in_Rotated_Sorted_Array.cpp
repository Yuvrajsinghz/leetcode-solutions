// Problem: Search in Rotated Sorted Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Approach: Modified Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Left half sorted
            if (nums[start] <= nums[mid]) {
                if (nums[start] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            } 
            // Right half sorted
            else {
                if (nums[mid] <= target && target <= nums[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1;
    }
};
