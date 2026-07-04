// Problem: Unique Paths
// Difficulty: Medium
// Approach: Dynamic Programming (2D DP)
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> matrix(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1];
            }
        }

        return matrix[m - 1][n - 1];
    }
};
