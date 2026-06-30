// Problem: Letter Combinations of a Phone Number
// Difficulty: Medium
// Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Approach: Backtracking
// Time Complexity: O(4^n * n)
// Space Complexity: O(n) (excluding output)

class Solution {
public:
    vector<string> result;

    void solve(string digits, int index,
               string current,
               vector<string>& map) {

        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        string letters = map[digits[index] - '0'];

        for (char ch : letters) {
            solve(digits, index + 1, current + ch, map);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        result.clear();

        vector<string> map = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        solve(digits, 0, "", map);

        return result;
    }
};
