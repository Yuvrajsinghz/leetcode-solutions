// Problem: Largest Positive Integer That Exists With Its Negative
// Difficulty: Easy
// Approach: Hash Set
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = -1;

        for (int x : nums) {
            if (x > 0 && set.count(-x)) {
                ans = max(ans, x);
            }
        }
        return ans;
    }
};
