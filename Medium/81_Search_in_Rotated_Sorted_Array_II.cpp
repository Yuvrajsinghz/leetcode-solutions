// Problem: Search in Rotated Sorted Array II
// Difficulty: Medium
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
// Approach: Modified Binary Search with Duplicates
// Time Complexity: O(log n) average, O(n) worst case
// Space Complexity: O(1)

class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int start = 0, end = arr.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                return true;
            }

            // ----- Handle Duplicates -----
            if (arr[start] == arr[mid] && arr[end] == arr[mid]) {
                start++;
                end--;
            }

            // ----- Left side sorted -----
            else if (arr[start] <= arr[mid]) {
                if (arr[start] <= target && target < arr[mid]) {
                    end = mid - 1;
                } else {
                    start = mid + 1;
                }
            }

            // ----- Right side sorted -----
            else {
                if (arr[mid] < target && target <= arr[end]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return false;
    }
};
