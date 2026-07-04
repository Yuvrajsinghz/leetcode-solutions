// Problem: Limit Occurrences in Array
// Difficulty: Easy
// Approach: Array Traversal
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> resultArr;

        for (int num : nums) {
            if (resultArr.size() < k ||
                resultArr[resultArr.size() - k] != num) {
                resultArr.push_back(num);
            }
        }

        return resultArr;
    }
};
