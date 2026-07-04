// Problem: Arranging Coins
// Difficulty: Easy
// Approach: Math (Quadratic Formula)
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)((sqrt(1 + 8.0 * n) - 1) / 2);
    }
};
