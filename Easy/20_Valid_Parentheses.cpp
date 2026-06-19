// Problem: Valid Parentheses
// Difficulty: Easy
// Link: https://leetcode.com/problems/valid-parentheses/
// Approach: Stack
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;

        for (char ch : str) {

            if (ch == '{' || ch == '(' || ch == '[') {
                st.push(ch);
                continue;
            }

            if (st.empty()) {
                return false;
            }

            char top = st.top();

            if ((ch == '}' && top != '{') ||
                (ch == ')' && top != '(') ||
                (ch == ']' && top != '[')) {
                return false;
            }

            st.pop();
        }

        return st.empty();
    }
};
