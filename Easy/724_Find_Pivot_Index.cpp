// Problem: Find Pivot Index
// Difficulty: Easy
// Approach: Prefix Sum
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int pivotIndex(vector<int>& arr) {
        int totalSum = 0;
        int prefixSum = 0;
        int suffixSum = 0;

        for (int i = 0; i < arr.size(); i++) {
            totalSum += arr[i];
        }

        for (int i = 0; i < arr.size(); i++) {
            suffixSum = totalSum - prefixSum - arr[i];

            if (prefixSum == suffixSum) {
                return i;
            }

            prefixSum += arr[i];
        }

        return -1;
    }
};
