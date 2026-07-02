// Problem: Search a 2D Matrix
// Difficulty: Medium
// Link: https://leetcode.com/problems/search-a-2d-matrix/
// Approach: Binary Search on Rows + Binary Search on Columns
// Time Complexity: O(log m + log n)
// Space Complexity: O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int column = matrix[0].size();

        int startRow = 0;
        int endRow = row - 1;

        while (startRow <= endRow) {

            int midRow =
                startRow + (endRow - startRow) / 2;

            if (matrix[midRow][0] <= target &&
                target <= matrix[midRow][column - 1]) {

                return searchInRow(matrix, target, midRow);
            }

            else if (matrix[midRow][0] > target) {
                endRow = midRow - 1;
            }

            else {
                startRow = midRow + 1;
            }
        }

        return false;
    }

    bool searchInRow(vector<vector<int>>& matrix,
                     int target,
                     int midRow) {

        int size = matrix[0].size();

        int start = 0;
        int end = size - 1;

        while (start <= end) {

            int mid =
                start + (end - start) / 2;

            if (matrix[midRow][mid] == target) {
                return true;
            }

            else if (matrix[midRow][mid] > target) {
                end = mid - 1;
            }

            else {
                start = mid + 1;
            }
        }

        return false;
    }
};
