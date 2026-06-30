// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Approach: Sliding Window + Hash Set
// Time Complexity: O(n)
// Space Complexity: O(min(n, charset))

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;

        int left = 0;
        int maxLen = 0;

        for (int right = 0; right < s.size(); right++) {

            while (st.count(s[right])) {
                st.erase(s[left]);
                left++;
            }

            st.insert(s[right]);

            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
