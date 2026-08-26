// Problem: Shortest and Lexicographically Smallest Beautiful String
// Difficulty: Medium
// Approach: Sliding Window
// Time Complexity: O(n²)  // substring creation/comparison
// Space Complexity: O(n)

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();

        int left = 0;
        int ones = 0;

        string ans = "";

        for (int right = 0; right < n; right++) {

            if (s[right] == '1') {
                ones++;
            }

            while (ones > k) {

                if (s[left] == '1') {
                    ones--;
                }

                left++;
            }

            // Remove leading zeros
            while (ones == k &&
                   left < right &&
                   s[left] == '0') {
                left++;
            }

            if (ones == k) {

                string cur =
                    s.substr(left, right - left + 1);

                if (ans.empty() ||
                    cur.size() < ans.size() ||
                    (cur.size() == ans.size() &&
                     cur < ans)) {

                    ans = cur;
                }
            }
        }

        return ans;
    }
};
