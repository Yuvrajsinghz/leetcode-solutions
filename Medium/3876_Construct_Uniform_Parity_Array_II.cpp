// Problem: Construct Uniform Parity Array II
// Difficulty: Medium
// Approach: Math / Observation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int mnOdd = INT_MAX;

        // Find the smallest odd element
        for (int x : nums) {
            if (x & 1) {
                mnOdd = min(mnOdd, x);
            }
        }

        // If an even number is smaller than the
        // smallest odd number, construction is impossible
        for (int x : nums) {
            if ((x % 2 == 0) &&
                mnOdd != INT_MAX &&
                x < mnOdd) {
                return false;
            }
        }

        return true;
    }
};
