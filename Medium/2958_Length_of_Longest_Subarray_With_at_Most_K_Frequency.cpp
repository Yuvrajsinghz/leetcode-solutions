// Problem: Maximum Subarray Length With Element Frequency Limited
// Difficulty: Medium
// Approach: Sliding Window + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        int left = 0;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            freq[nums[right]]++;

            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};
