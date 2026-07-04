// Problem: Maximum Total Value
// Difficulty: Easy
// Approach: Find Global Minimum and Maximum
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long gMin = *min_element(nums.begin(), nums.end());
        long long gMax = *max_element(nums.begin(), nums.end());

        return (gMax - gMin) * k;
    }
};
