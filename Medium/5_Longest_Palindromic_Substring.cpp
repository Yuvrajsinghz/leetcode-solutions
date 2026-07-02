// Problem: Longest Palindromic Substring
// Difficulty: Medium
// Link: https://leetcode.com/problems/longest-palindromic-substring/
// Approach: Manacher's Algorithm
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string longestPalindrome(string s) {

        // Transform string
        string t = "#";

        for (char c : s) {
            t += c;
            t += "#";
        }

        int n = t.size();

        vector<int> p(n, 0);

        int center = 0;
        int right = 0;

        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {

            int mirror = 2 * center - i;

            if (i < right) {
                p[i] = min(right - i, p[mirror]);
            }

            // expand around center
            int a = i + p[i] + 1;
            int b = i - p[i] - 1;

            while (a < n &&
                   b >= 0 &&
                   t[a] == t[b]) {

                p[i]++;
                a++;
                b--;
            }

            // update center and right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            // update longest palindrome
            if (p[i] > maxLen) {
                maxLen = p[i];
                start = (i - maxLen) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
