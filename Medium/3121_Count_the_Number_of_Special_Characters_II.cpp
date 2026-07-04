// Problem: Count the Number of Special Characters II
// Difficulty: Medium
// Approach: First Uppercase and Last Lowercase Tracking
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lastlower(26, -1);
        vector<int> firstUpper(26, -1);

        int count = 0;

        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];

            if (islower(ch)) {
                lastlower[ch - 'a'] = i;
            }
            else if (firstUpper[ch - 'A'] == -1) {
                firstUpper[ch - 'A'] = i;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (lastlower[i] != -1 &&
                firstUpper[i] != -1 &&
                firstUpper[i] > lastlower[i]) {
                count++;
            }
        }

        return count;
    }
};
