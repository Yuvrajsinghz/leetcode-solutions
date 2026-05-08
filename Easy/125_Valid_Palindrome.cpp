// Problem: Valid Palindrome
// Difficulty: Easy
// Link: https://leetcode.com/problems/valid-palindrome/
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isAlphaNum(char ch) {
        if ((ch >= '0' && ch <= '9') ||
            (ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z')) {
            return true;
        }

        return false;
    }

    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {

            if (!isAlphaNum(s[start])) {
                start++;
                continue;
            }

            if (!isAlphaNum(s[end])) {
                end--;
                continue;
            }

            if (tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};
