// Problem: Find the Difference
// Difficulty: Easy
// Approach: Bit Manipulation (XOR)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    char findTheDifference(string s, string t) {
        char answer = 0;

        for (int i = 0; i < s.size(); i++) {
            answer ^= s[i];
        }

        for (int i = 0; i < t.size(); i++) {
            answer ^= t[i];
        }

        return answer;
    }
};
