// Problem: Count Subarrays Where Target is Majority
// Difficulty: Medium
// Approach: Brute Force (Nested Loops)
// Time Complexity: O(n^2)
// Space Complexity: O(1)

class Solution {
public:
    int countMajoritySubarrays(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int tempMajor = 0;

            for (int j = i; j < n; j++) {

                if (arr[j] == target) {
                    tempMajor++;
                }

                int len = j - i + 1;

                if (tempMajor > len / 2) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
