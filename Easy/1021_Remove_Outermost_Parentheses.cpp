// Problem: Remove Outermost Parentheses
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-outermost-parentheses/
// Approach: Depth Counting
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string removeOuterParentheses(string str) {
        string result;
        int opened = 0;

        for (char ch : str) {

            if (ch == '(' && opened++ > 0) {
                result += ch;
            }

            if (ch == ')' && opened-- > 1) {
                result += ch;
            }
        }

        return result;
    }
};
