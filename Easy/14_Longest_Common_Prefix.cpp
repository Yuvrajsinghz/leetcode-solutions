// Problem: Longest Common Prefix
// Difficulty: Easy
// Approach: Horizontal Scanning
// Time Complexity: O(n * m)
// Space Complexity: O(1)

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if (strs.empty())
            return "";

        string prefix = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            while (strs[i].find(prefix) != 0) {
                prefix.pop_back();

                if (prefix.empty())
                    return "";
            }
        }

        return prefix;
    }
};
