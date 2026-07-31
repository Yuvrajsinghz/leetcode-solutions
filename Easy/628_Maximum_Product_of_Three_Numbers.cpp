// Problem: Maximum Product of Three Numbers
// Difficulty: Easy
// Approach: Track Three Largest and Two Smallest Numbers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int num : nums) {

            // Two smallest numbers
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num < min2) {
                min2 = num;
            }

            // Three largest numbers
            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num >= max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num > max3) {
                max3 = num;
            }
        }

        return max(max1 * max2 * max3,
                   max1 * min1 * min2);
    }
};
