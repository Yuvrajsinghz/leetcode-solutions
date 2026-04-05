// Problem: Next Permutation
// Difficulty: Medium
// Link: https://leetcode.com/problems/next-permutation/
// Approach: Find Breakpoint + Swap + Reverse
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i = n - 2;

        // find breakpoint
        while (i >= 0 && arr[i] >= arr[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;

            while (arr[j] <= arr[i]) {
                j--;
            }

            swap(arr[i], arr[j]);
        }

        reverse(arr.begin() + i + 1, arr.end());
    }
};
