// Problem: Find Greatest Common Divisor of Array
// Difficulty: Easy
// Approach: Find Minimum and Maximum, then Compute GCD
// Time Complexity: O(n + log(max(nums)))
// Space Complexity: O(1)

class Solution {
public:
    int findGCD(vector<int>& nums) {

        int mxVal = *max_element(nums.begin(), nums.end());
        int mnVal = *min_element(nums.begin(), nums.end());

        return gcd(mnVal, mxVal);
    }
};
