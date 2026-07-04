// Problem: Maximize Building Height
// Difficulty: Hard
// Approach: Greedy + Forward & Backward Constraints
// Time Complexity: O(m log m)
// Space Complexity: O(1) (ignoring input modifications)

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1, 0});

        int maxPeak = 0;

        sort(res.begin(), res.end());

        if (res[res.size() - 1][0] != n) {
            res.push_back({n, n - 1});
        }

        int m = res.size();

        // Forward pass (left to right constraint propagation)
        for (int i = 1; i < m; i++) {
            int dis = res[i][0] - res[i - 1][0];
            res[i][1] = min(res[i][1], res[i - 1][1] + dis);
        }

        // Backward pass (right to left constraint propagation)
        for (int i = m - 2; i >= 0; i--) {
            int dis = res[i + 1][0] - res[i][0];
            res[i][1] = min(res[i][1], res[i + 1][1] + dis);
        }

        // Compute best peak between adjacent restrictions
        for (int i = 0; i < m - 1; i++) {
            int d = res[i + 1][0] - res[i][0];
            int h1 = res[i][1];
            int h2 = res[i + 1][1];

            int peak = (h1 + h2 + d) / 2;

            maxPeak = max(maxPeak, peak);
        }

        return maxPeak;
    }
};
