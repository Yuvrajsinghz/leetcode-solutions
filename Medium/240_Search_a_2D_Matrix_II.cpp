// Problem: Search a 2D Matrix II
// Difficulty: Medium
// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/
// Approach: Staircase Search (Top-Right Corner)
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }

        int row = 0;
        int column = matrix[0].size() - 1;

        while (row < matrix.size() &&
               column >= 0) {

            if (matrix[row][column] == target) {
                return true;
            }

            else if (target < matrix[row][column]) {
                column--;
            }

            else {
                row++;
            }
        }

        return false;
    }
};
