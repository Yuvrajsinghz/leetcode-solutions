// Problem: Multiply Strings
// Difficulty: Medium
// Link: https://leetcode.com/problems/multiply-strings/
// Approach: School Multiplication Simulation
// Time Complexity: O(m * n)
// Space Complexity: O(m + n)

class Solution {
public:
    string multiply(string num1, string num2) {

        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        if (num1 == "1") {
            return num2;
        }

        if (num2 == "1") {
            return num1;
        }

        int m = num1.size();
        int n = num2.size();

        vector<int> ans(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                ans[i + j + 1] +=
                    (num1[i] - '0') *
                    (num2[j] - '0');

                ans[i + j] += ans[i + j + 1] / 10;
                ans[i + j + 1] %= 10;
            }
        }

        int i = 0;

        while (i < ans.size() && ans[i] == 0) {
            i++;
        }

        string result = "";

        while (i < ans.size()) {
            result.push_back(ans[i++] + '0');
        }

        return result;
    }
};
