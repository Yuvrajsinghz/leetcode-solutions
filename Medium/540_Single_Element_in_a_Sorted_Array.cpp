// Problem: Single Element in a Sorted Array
// Difficulty: Medium
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Approach: Binary Search (Index Pairing Trick)
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // ensure mid is even
            if (mid % 2 == 1)
                mid--;

            if (nums[mid] == nums[mid + 1]) {
                start = mid + 2; // right side
            } else {
                end = mid; // left side
            }
        }

        return nums[start];
    }
};
