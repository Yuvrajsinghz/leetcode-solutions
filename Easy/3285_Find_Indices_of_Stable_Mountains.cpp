// Problem: Find Indices of Stable Mountains
// Difficulty: Easy
// Link: https://leetcode.com/problems/find-indices-of-stable-mountains/
// Approach: Linear Scan
// Time Complexity: O(n)
// Space Complexity: O(1) excluding output

class Solution {
public:
    vector<int> stableMountains(vector<int>& height, int threshold) {

        vector<int> ans;

        for (int i = 1; i < height.size(); i++) {

            if (height[i - 1] > threshold) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
