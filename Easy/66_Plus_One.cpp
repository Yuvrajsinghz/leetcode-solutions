// Problem: Plus One
// Difficulty: Easy
// Link: https://leetcode.com/problems/plus-one/
// Approach: Simulation (Carry Handling)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                return digits;
            }
        }

        digits.insert(digits.begin(), 1);
        return digits;
    }
};
