// Problem: Number of Substrings Containing All Three Characters
// Difficulty: Medium
// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
// Approach: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfSubstrings(string s) {
        int ans = 0;
        int left = 0;
        int n = s.size();

        vector<int> freq(3, 0);

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'a']++;

            while (freq[0] > 0 &&
                   freq[1] > 0 &&
                   freq[2] > 0) {

                ans += (n - right);

                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};
