// Problem: Removing Stars From a String
// Difficulty: Medium
// Approach: Stack Simulation (String as Stack)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string removeStars(string s) {
        string ans;

        for (char ch : s) {
            if (ch == '*') {
                ans.pop_back();
            }
            else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};
