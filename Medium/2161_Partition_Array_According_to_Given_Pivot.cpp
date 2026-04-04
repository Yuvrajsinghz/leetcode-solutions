// Problem: Partition Array According to Given Pivot
// Difficulty: Medium
// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/
// Approach: Three Arrays (Partitioning)
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> pivotArray(vector<int>& arr, int pivot) {
        vector<int> less, equal, greater;
        
        for (int num : arr) {
            if (num < pivot) {
                less.push_back(num);
            } 
            else if (num == pivot) {
                equal.push_back(num);
            } 
            else {
                greater.push_back(num);
            }
        }
        
        // merge all
        vector<int> result;
        
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());
        
        return result;
    }
};
