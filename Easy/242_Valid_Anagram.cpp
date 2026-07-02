// Problem: Valid Anagram
// Difficulty: Easy
// Link: https://leetcode.com/problems/valid-anagram/
// Approach: Frequency Count
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        vector<int> count(26, 0);

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int c : count) {
            if (c != 0) {
                return false;
            }
        }

        return true;
    }
};
