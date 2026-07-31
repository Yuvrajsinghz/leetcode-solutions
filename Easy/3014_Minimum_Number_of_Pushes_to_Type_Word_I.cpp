// Problem: Minimum Number of Pushes to Type Word I
// Difficulty: Easy
// Approach: Greedy Counting
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minimumPushes(string word) {

        int ans = 0;

        for (int i = 0; i < word.size(); i++) {
            ans += (i / 8) + 1;
        }

        return ans;
    }
};
