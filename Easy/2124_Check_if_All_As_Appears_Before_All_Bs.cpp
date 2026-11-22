// Problem: 2124. Check if All A's Appears Before All B's
// Difficulty: Easy
// Approach: String / STL
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool checkString(string s) {
        return s.find("ba") == string::npos;
    }
};
