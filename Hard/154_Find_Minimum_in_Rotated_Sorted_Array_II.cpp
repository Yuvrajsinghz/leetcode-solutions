// Problem: Find Minimum in Rotated Sorted Array II
// Difficulty: Hard
// Time Complexity:
// Average: O(log n)
// Worst: O(n)
//
// Space Complexity: O(1)

class Solution {
public:
    int findMin(vector<int>& arr) {

        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {

            int mid =
                start + (end - start) / 2;

            if (arr[mid] > arr[end]) {
                start = mid + 1;
            }
            else if (arr[mid] < arr[end]) {
                end = mid;
            }
            else {
                end--;
            }
        }

        return arr[start];
    }
};
