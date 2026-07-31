// Problem: Minimum Number of Pushes to Type Word II
// Difficulty: Medium
// Approach: Greedy + Frequency Sorting
// Time Complexity: O(n + 26 log 26)
// Space Complexity: O(26)

class Solution {
public:
    int minimumPushes(string word) {

        vector<int> freq(26, 0);

        for (char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int ans = 0;

        for (int i = 0; i < 26; i++) {
            ans += freq[i] * (i / 8 + 1);
        }

        return ans;
    }
};
