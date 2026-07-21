// Problem: Minimum Add to Make Parentheses Valid
// Difficulty: Medium
// Approach: Balance Counter
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minAddToMakeValid(string s) {

        int balance = 0;
        int ans = 0;

        for (char ch : s) {

            if (ch == '(') {
                balance++;
            }
            else {

                if (balance > 0) {
                    balance--;
                }
                else {
                    ans++;
                }
            }
        }

        return balance + ans;
    }
};
