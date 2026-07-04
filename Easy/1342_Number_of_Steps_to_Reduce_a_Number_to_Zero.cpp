// Problem: Number of Steps to Reduce a Number to Zero
// Difficulty: Easy
// Approach: Simulation
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int numberOfSteps(int num) {
        int temp = num;
        int i = 0;

        for (i = 0; temp != 0; i++) {
            if (temp % 2 == 0) {
                temp /= 2;
            }
            else {
                temp--;
            }
        }

        return i;
    }
};
