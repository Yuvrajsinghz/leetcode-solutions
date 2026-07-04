// Problem: Kth Largest Element in an Array
// Difficulty: Medium
// Approach: Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1) extra (ignoring sort)

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() - k];
    }
};
