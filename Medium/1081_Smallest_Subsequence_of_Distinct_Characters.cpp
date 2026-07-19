// Problem: Smallest Subsequence of Distinct Characters
// Difficulty: Medium
// Approach: Monotonic Stack (using String as Stack)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    string smallestSubsequence(string s) {

        vector<int> lastOcc(26);
        vector<bool> inStack(26, false);
        string str;

        for (int i = 0; i < s.size(); i++) {
            lastOcc[s[i] - 'a'] = i;
        }

        for (int i = 0; i < s.size(); i++) {

            char ch = s[i];

            if (inStack[ch - 'a']) {
                continue;
            }

            while (!str.empty() &&
                   str.back() > ch &&
                   lastOcc[str.back() - 'a'] > i) {

                inStack[str.back() - 'a'] = false;
                str.pop_back();
            }

            str.push_back(ch);
            inStack[ch - 'a'] = true;
        }

        return str;
    }
};
