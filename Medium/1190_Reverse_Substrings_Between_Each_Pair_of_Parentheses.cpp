// Problem: Reverse Substrings Between Each Pair of Parentheses
// Difficulty: Medium
// Link: https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
// Approach: Stack
// Time Complexity: O(n^2)
// Space Complexity: O(n)

class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr;

        for (char ch : s) {
            if (ch == '(') {
                st.push(curr);
                curr = "";
            }
            else if (ch == ')') {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};