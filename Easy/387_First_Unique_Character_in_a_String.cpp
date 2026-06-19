// Problem: First Unique Character in a String
// Difficulty: Easy
// Link: https://leetcode.com/problems/first-unique-character-in-a-string/
// Approach: Hash Map Frequency Count
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int firstUniqChar(string str) {
        unordered_map<char, int> map;

        for (char ch : str) {
            map[ch]++;
        }

        for (int i = 0; i < str.size(); i++) {
            if (map[str[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
