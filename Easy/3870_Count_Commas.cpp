// Problem: 3870. Count Commas
// Difficulty: Easy
// Approach: Math
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int countCommas(int n) {
        return max(0, n - 999);
    }
};
