// Problem: Maximum Product of Two Elements in an Array
// Difficulty: Easy
// Approach: Track Two Largest Elements
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int max1 = 0;
        int max2 = 0;

        for (int num : nums) {

            if (num > max1) {
                max2 = max1;
                max1 = num;
            }
            else if (num > max2) {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
