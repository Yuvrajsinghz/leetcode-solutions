// Problem: Diagonal Traverse
// Difficulty: Medium
// Approach: Diagonal Traversal + Reverse Alternate Diagonals
// Time Complexity: O(m * n)
// Space Complexity: O(min(m, n))

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> ans;

        for (int d = 0; d < m + n - 1; d++) {

            int row = (d < n) ? 0 : d - n + 1;
            int colu = (d < n) ? d : n - 1;

            vector<int> temp;

            while (row < m && colu >= 0) {
                temp.push_back(mat[row][colu]);
                row++;
                colu--;
            }

            if (d % 2 == 0) {
                reverse(temp.begin(), temp.end());
            }

            ans.insert(ans.end(), temp.begin(), temp.end());
        }

        return ans;
    }
};
