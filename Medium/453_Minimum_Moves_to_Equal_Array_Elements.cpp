// Problem: Minimum Moves to Equal Array Elements
// Difficulty: Medium
// Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
// Approach: Math
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minMoves(vector<int>& arr) {
        int minVal = *min_element(arr.begin(), arr.end());
        int moves = 0;

        for (int val : arr) {
            moves += (val - minVal);
        }

        return moves;
    }
};
