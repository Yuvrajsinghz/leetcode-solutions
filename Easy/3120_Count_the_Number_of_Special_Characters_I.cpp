// Problem: Count the Number of Special Characters I
// Difficulty: Easy
// Approach: Two Sets
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfSpecialChars(string word) {
        set<char> lower, upper;
        int count = 0;

        for (int ch : word) {
            if (islower(ch)) {
                lower.insert(ch);
            }
            else {
                upper.insert(tolower(ch));
            }
        }

        for (int ch : lower) {
            if (upper.find(ch) != upper.end()) {
                count++;
            }
        }

        return count;
    }
};
