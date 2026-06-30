// Problem: Roman to Integer
// Difficulty: Easy
// Link: https://leetcode.com/problems/roman-to-integer/
// Approach: Hash Map + Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int romanToInt(string str) {
        unordered_map<char, int> map;

        map['I'] = 1;
        map['V'] = 5;
        map['X'] = 10;
        map['L'] = 50;
        map['C'] = 100;
        map['D'] = 500;
        map['M'] = 1000;

        int result = 0;

        for (int i = 0; i < str.length(); i++) {
            if (i + 1 < str.length() &&
                map[str[i]] < map[str[i + 1]]) {
                result -= map[str[i]];
            } else {
                result += map[str[i]];
            }
        }

        return result;
    }
};
