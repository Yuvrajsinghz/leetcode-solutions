// Problem: String Compression
// Difficulty: Medium
// Link: https://leetcode.com/problems/string-compression/
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0;
        int idx = 0;

        while (i < n) {
            char ch = chars[i];
            int count = 0;

            // count frequency
            while (i < n && chars[i] == ch) {
                i++;
                count++;
            }

            // write character
            chars[idx++] = ch;

            // write count if greater than 1
            if (count > 1) {
                string str = to_string(count);

                for (char c : str) {
                    chars[idx++] = c;
                }
            }
        }

        return idx;
    }
};
