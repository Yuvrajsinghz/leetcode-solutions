// Problem: Maximum Ice Cream Bars
// Difficulty: Medium
// Approach: Greedy + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int bars = 0;

        sort(costs.begin(), costs.end());

        for (int cost : costs) {
            if (coins < cost) {
                break;
            }

            coins -= cost;
            bars++;
        }

        return bars;
    }
};
