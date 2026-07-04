// Problem: Running Sum of 1d Array
// Difficulty: Easy
// Approach: Prefix Sum (In-Place)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> runningSum(vector<int>& arr) {
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = arr[i] + arr[i - 1];
        }
        return arr;
    }
};
