// Problem: Minimum Cost of Buying Candies With Discount
// Difficulty: Easy
// Approach: Greedy + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());

        int ans = 0;

        for (int i = 0; i < cost.size(); i++) {
            if ((i + 1) % 3 != 0) {
                ans += cost[i];
            }
        }

        return ans;
    }
};
