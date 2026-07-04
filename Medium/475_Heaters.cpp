// Problem: Heaters
// Difficulty: Medium
// Approach: Binary Search (Lower Bound)
// Time Complexity: O(n log m)
// Space Complexity: O(1)

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int ans = 0;

        sort(heaters.begin(), heaters.end());

        for (int house : houses) {

            int idx = lower_bound(heaters.begin(), heaters.end(), house)
                      - heaters.begin();

            int rightDis = INT_MAX;
            int leftDis = INT_MAX;

            if (idx > 0) {
                leftDis = house - heaters[idx - 1];
            }

            if (idx < heaters.size()) {
                rightDis = heaters[idx] - house;
            }

            int dis = min(leftDis, rightDis);

            ans = max(ans, dis);
        }

        return ans;
    }
};
