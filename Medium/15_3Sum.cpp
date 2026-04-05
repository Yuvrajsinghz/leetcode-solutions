// Problem: 3Sum
// Difficulty: Medium
// Link: https://leetcode.com/problems/3sum/
// Approach: Sorting + Two Pointers
// Time Complexity: O(n^2)
// Space Complexity: O(1) (excluding result)

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> result;

        for (int i = 0; i < arr.size(); i++) {
            if (i > 0 && arr[i] == arr[i - 1]) {
                continue;
            }

            int left = i + 1, right = arr.size() - 1;

            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];

                if (sum == 0) {
                    result.push_back({arr[i], arr[left], arr[right]});

                    while (left < right && arr[left] == arr[left + 1]) {
                        left++;
                    }
                    while (left < right && arr[right] == arr[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                } 
                else if (sum < 0) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
