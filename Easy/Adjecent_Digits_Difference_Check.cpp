// Problem: Adjacent Digits Difference Check
// Difficulty: Easy
// Approach: String Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for (int i = 0; i < s.size() - 1; i++) {
            if (abs(s[i] - s[i + 1]) > 2) {
                return false;
            }
        }
        return true;
    }
};
