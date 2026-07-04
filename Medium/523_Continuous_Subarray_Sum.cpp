// Problem: Continuous Subarray Sum
// Difficulty: Medium
// Approach: Prefix Sum + Hash Map
// Time Complexity: O(n)
// Space Complexity: O(min(n, k))

class Solution {
public:
    bool checkSubarraySum(vector<int>& arr, int k) {
        unordered_map<int, int> map;
        int prifixSum = 0;

        map[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            prifixSum += arr[i];

            int reminder = prifixSum % k;

            if (map.count(reminder)) {
                if (i - map[reminder] >= 2) {
                    return true;
                }
            }
            else {
                map[reminder] = i;
            }
        }

        return false;
    }
};
