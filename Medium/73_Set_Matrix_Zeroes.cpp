// Problem: Set Matrix Zeroes
// Difficulty: Medium
// Approach: In-Place Marking (First Row & First Column)
// Time Complexity: O(m * n)
// Space Complexity: O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        bool firstCol = false;

        // Mark rows and columns
        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0)
                firstCol = true;

            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Fill zeros using markers
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 1; j--) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }

            if (firstCol)
                matrix[i][0] = 0;
        }
    }
};
