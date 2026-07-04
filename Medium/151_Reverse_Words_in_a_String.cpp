// Problem: Reverse Words in a String
// Difficulty: Medium
// Approach: Reverse Whole String + Word Processing
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0, start = 0;
        int n = s.size();

        reverse(s.begin(), s.end());

        while (i < n) {

            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)
                break;

            start = j;

            while (i < n && s[i] != ' ') {
                s[j++] = s[i++];
            }

            reverse(s.begin() + start, s.begin() + j);

            s[j++] = ' ';
        }

        if (j > 0)
            j--;

        s.resize(j);

        return s;
    }
};
