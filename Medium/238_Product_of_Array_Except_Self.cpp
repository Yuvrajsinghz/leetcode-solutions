// Problem: Product of Array Except Self
// Difficulty: Medium
// Link: https://leetcode.com/problems/product-of-array-except-self/
// Approach: Prefix Product + Suffix Product
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding output array)

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        // prefix product
        for (int i = 1; i < n; i++) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        // suffix product
        int right = 1;

        for (int i = n - 1; i >= 0; i--) {
            ans[i] = ans[i] * right;
            right *= nums[i];
        }

        return ans;
    }
};
