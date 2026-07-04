// Problem: Range Sum Query 2D - Immutable
// Difficulty: Medium
// Approach: 2D Prefix Sum
// Time Complexity: O(m * n) for constructor, O(1) per query
// Space Complexity: O(m * n)

class NumMatrix {
public:
    vector<vector<int>> prefixMatrix;

    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        prefixMatrix.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                prefixMatrix[i][j] =
                    matrix[i - 1][j - 1]
                    + prefixMatrix[i][j - 1]
                    + prefixMatrix[i - 1][j]
                    - prefixMatrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixMatrix[row2 + 1][col2 + 1]
             - prefixMatrix[row1][col2 + 1]
             - prefixMatrix[row2 + 1][col1]
             + prefixMatrix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
