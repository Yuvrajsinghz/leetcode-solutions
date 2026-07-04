// Problem: Number of Strings That Appear as Substrings in Word
// Difficulty: Easy
// Approach: String Matching (find)
// Time Complexity: O(n * m)
// Space Complexity: O(1)

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};
