// Problem: Zigzag Conversion
// Difficulty: Medium
// Approach: Row Simulation
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string convert(string s, int numRows) {

        if (numRows == 1) {
            return s;
        }

        vector<string> rows(numRows);

        string ansRow;

        int currentRow = 0;
        bool direction = false;

        for (char ch : s) {

            rows[currentRow] += ch;

            if (currentRow == 0 || currentRow == numRows - 1) {
                direction = !direction;
            }

            currentRow += direction ? 1 : -1;
        }

        for (string& row : rows) {
            ansRow += row;
        }

        return ansRow;
    }
};
