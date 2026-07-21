// Problem: Height Checker
// Difficulty: Easy
// Approach: Compare Original Array with Sorted Array
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    int heightChecker(vector<int>& heights) {

        vector<int> exp;
        int count = 0;

        for (int height : heights) {
            exp.push_back(height);
        }

        sort(exp.begin(), exp.end());

        for (int i = 0; i < heights.size(); i++) {
            if (heights[i] != exp[i]) {
                count++;
            }
        }

        return count;
    }
};
