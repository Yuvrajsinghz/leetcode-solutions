// Problem: Maximum Length Substring With Two Occurrences
// Difficulty: Easy
// Approach: Sliding Window + Frequency Array
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maximumLengthSubstring(string s) {
        int cnt[26] = {};
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            cnt[s[right] - 'a']++;

            while (cnt[s[right] - 'a'] > 2) {
                cnt[s[left] - 'a']--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
