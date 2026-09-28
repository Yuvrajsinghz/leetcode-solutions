// Problem: Maximum Nesting Depth of the Parentheses
// Difficulty: Easy
// Link: https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
// Approach: Traverse the string and maintain the current parenthesis depth.
//            Increment depth for '(' and decrement for ')'.
//            Track the maximum depth reached.
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int maxCnt = 0;

        for (char ch : s) {
            if (ch == '(') {
                cnt++;
                maxCnt = max(maxCnt, cnt);
            } 
            else if (ch == ')') {
                cnt--;
            }
        }

        return maxCnt;
    }
};