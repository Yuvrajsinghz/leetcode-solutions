// Problem: Process String With Special Operations I
// Difficulty: Medium
// Approach: String Simulation
// Time Complexity: O(2^n)
// Space Complexity: O(n)

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        int n = s.size();

        for (int i = 0; i < n; i++) {

            char ch = s[i];

            if (islower(ch)) {
                ans.push_back(ch);
            }
            else if (ch == '*' && !ans.empty()) {
                ans.pop_back();
            }
            else if (ch == '#') {
                ans += ans;
            }
            else if (ch == '%') {
                reverse(ans.begin(), ans.end());
            }
        }

        return ans;
    }
};
