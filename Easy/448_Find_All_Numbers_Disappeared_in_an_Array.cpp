// Problem: Find All Numbers Disappeared in an Array
// Difficulty: Easy
// Approach: Mark Visited Indices Using Negative Sign
// Time Complexity: O(n)
// Space Complexity: O(1) (excluding output array)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {

        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int index = abs(nums[i]) - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};
