// Problem: Move Zeroes
// Difficulty: Easy
// Link: https://leetcode.com/problems/move-zeroes/
// Approach: Two Pointers (Overwrite + Fill Zeros)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i = 0, j = 0;

        while (i < arr.size()) {
            if (arr[i] != 0) {
                arr[j] = arr[i];
                j++;
            }
            i++;
        }

        while (j < arr.size()) {
            arr[j] = 0;
            j++;
        }
    }
};
