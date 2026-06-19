// Problem: 3Sum Closest
// Difficulty: Medium
// Link: https://leetcode.com/problems/3sum-closest/
// Approach: Sorting + Two Pointers
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int closestSum = arr[0] + arr[1] + arr[2];

        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int currentSum = arr[i] + arr[left] + arr[right];

                // update closest sum
                if (abs(target - currentSum) <
                    abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                }
                else if (currentSum > target) {
                    right--;
                }
                else {
                    return currentSum; // exact match
                }
            }
        }

        return closestSum;
    }
};
