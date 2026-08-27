// Problem: Lexicographically Smallest String Greater Than Target
// Difficulty: Medium
// Approach: Greedy + Frequency Counting
// Time Complexity: O(26 * n)
// Space Complexity: O(26)

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {

        vector<int> left(26, 0);

        // Frequency difference
        for (int i = 0; i < s.size(); i++) {
            left[s[i] - 'a']++;
            left[target[i] - 'a']--;
        }

        // Try to increase target from right to left
        for (int i = target.size() - 1; i >= 0; i--) {

            int b = target[i] - 'a';

            left[b]++;

            bool ok = true;

            for (int x : left) {
                if (x < 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok)
                continue;

            int bigger = -1;

            for (int j = b + 1; j < 26; j++) {
                if (left[j] > 0) {
                    bigger = j;
                    break;
                }
            }

            if (bigger == -1)
                continue;

            left[bigger]--;

            string ans = target.substr(0, i);

            ans.push_back('a' + bigger);

            // Fill remaining characters in sorted order
            for (int j = 0; j < 26; j++) {
                ans.append(left[j], 'a' + j);
            }

            return ans;
        }

        return "";
    }
};
