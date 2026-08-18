// Problem: Find the Largest Almost Missing Integer
// Difficulty: Easy
// Approach: Frequency Counting
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // k == 1
        // Har subarray ki length 1 hai,
        // isliye jo number sirf ek baar aaya hai
        // wahi exactly ek subarray mein present hoga.
        if (k == 1) {
            int ans = -1;

            for (auto& [num, count] : freq) {
                if (count == 1) {
                    ans = max(ans, num);
                }
            }

            return ans;
        }

        // k == n
        // Sirf ek hi subarray hai: poora array.
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // 1 < k < n
        // Sirf first aur last element aise ho sakte hain
        // jo exactly ek subarray mein appear karein.
        int ans = -1;

        if (freq[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (freq[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};
