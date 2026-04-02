// Problem: Third Maximum Number
// Difficulty: Easy
// Link: https://leetcode.com/problems/third-maximum-number/
// Approach: Tracking Top 3 Maximums
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long firstMaxVal = LONG_MIN, secondMaxVal = LONG_MIN, thirdMaxVal = LONG_MIN;

        for (int num : nums) {

            if (num == firstMaxVal || num == secondMaxVal || num == thirdMaxVal)
                continue;

            if (num > firstMaxVal) {
                thirdMaxVal = secondMaxVal;
                secondMaxVal = firstMaxVal;
                firstMaxVal = num;
            } 
            else if (num > secondMaxVal) {
                thirdMaxVal = secondMaxVal;
                secondMaxVal = num;
            } 
            else if (num > thirdMaxVal) {
                thirdMaxVal = num;
            }
        }

        return (thirdMaxVal == LONG_MIN) ? firstMaxVal : thirdMaxVal;
    }
};
