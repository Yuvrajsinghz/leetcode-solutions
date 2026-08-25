// Problem: Missing Multiple
// Difficulty: Easy
// Link: LeetCode
// Approach: Use an unordered_set to store all elements, then check multiples of k until a missing one is found.
// Time Complexity: O(n) average
// Space Complexity: O(n)

class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());

        int x = k;

        while (st.count(x)) {
            x += k;
        }

        return x;
    }
};