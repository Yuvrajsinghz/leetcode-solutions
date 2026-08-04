// Problem: Find Missing Elements
// Difficulty: Easy
// Approach: Presence Array
// Time Complexity: O(n + range)
// Space Complexity: O(range)

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int minElement = *min_element(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());

        vector<bool> exists(maxElement - minElement + 1, false);

        for (int num : nums) {
            exists[num - minElement] = true;
        }

        vector<int> ans;

        for (int i = 0; i <= maxElement - minElement; i++) {
            if (!exists[i]) {
                ans.push_back(i + minElement);
            }
        }

        return ans;
    }
};
