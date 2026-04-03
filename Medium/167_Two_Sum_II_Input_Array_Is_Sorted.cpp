// Problem: Two Sum II - Input Array Is Sorted
// Difficulty: Medium
// Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
// Approach: Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;

        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                return {i + 1, j + 1};
            } 
            else if (numbers[i] + numbers[j] < target) {
                i++;
            } 
            else {
                j--;
            }
        }

        return {};
    }
};
