// Problem: Spiral Matrix
// Difficulty: Medium
// Link: https://leetcode.com/problems/spiral-matrix/
// Approach: Boundary Traversal
// Time Complexity: O(m * n)
// Space Complexity: O(1) Auxiliary Space

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> finalAnswer;

        int rows = matrix.size();
        int columns = matrix[0].size();

        int top = 0;
        int bottom = rows - 1;

        int left = 0;
        int right = columns - 1;

        while (top <= bottom && left <= right) {

            // Left -> Right
            for (int i = left; i <= right; i++) {
                finalAnswer.push_back(matrix[top][i]);
            }
            top++;

            // Top -> Bottom
            for (int i = top; i <= bottom; i++) {
                finalAnswer.push_back(matrix[i][right]);
            }
            right--;

            // Right -> Left
            if (top <= bottom) {
                for (int i = right; i >= left; i--) {
                    finalAnswer.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            // Bottom -> Top
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    finalAnswer.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return finalAnswer;
    }
};
