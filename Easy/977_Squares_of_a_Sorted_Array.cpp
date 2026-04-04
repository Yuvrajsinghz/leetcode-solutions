// Problem: Squares of a Sorted Array
// Difficulty: Easy
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
        int n = arr.size();
        vector<int> result(n);

        int left = 0, right = n - 1;
        int k = n - 1;

        while (left <= right) {
            if (abs(arr[left]) > abs(arr[right])) {
                result[k] = arr[left] * arr[left];
                left++;
            } else {
                result[k] = arr[right] * arr[right];
                right--;
            }
            k--;
        }

        return result;
    }
};
