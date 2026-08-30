// Problem: Removing Minimum and Maximum From Array
// Difficulty: Medium
// Approach: Greedy / Case Analysis
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {

        int n = nums.size();

        int minIndex =
            min_element(nums.begin(), nums.end()) - nums.begin();

        int maxIndex =
            max_element(nums.begin(), nums.end()) - nums.begin();

        if (minIndex > maxIndex) {
            swap(minIndex, maxIndex);
        }

        // Remove both from front
        int left = maxIndex + 1;

        // Remove both from back
        int right = n - minIndex;

        // Remove one from front and one from back
        int both =
            (minIndex + 1) +
            (n - maxIndex);

        return min({left, right, both});
    }
};
