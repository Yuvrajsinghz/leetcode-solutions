// Problem: Maximum Product Subarray
// Difficulty: Medium
// Approach: Dynamic Programming (Track Max & Min Product)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxPro = arr[0];
        int minPro = arr[0];
        int ans = arr[0];

        int m = arr.size();

        for (int i = 1; i < m; i++) {

            int curr = arr[i];

            int tempMax = max({curr, curr * maxPro, curr * minPro});
            int tempMin = min({curr, curr * maxPro, curr * minPro});

            maxPro = tempMax;
            minPro = tempMin;

            ans = max(ans, maxPro);
        }

        return ans;
    }
};
