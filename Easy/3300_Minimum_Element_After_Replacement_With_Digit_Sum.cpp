// Problem: Minimum Element After Replacement With Digit Sum
// Difficulty: Easy
// Approach: Digit Sum Simulation
// Time Complexity: O(n * d)
// Space Complexity: O(1)

class Solution {
public:
    int minElement(vector<int>& arr) {
        int minEle = INT_MAX;

        for (int i = 0; i < arr.size(); i++) {
            int sum = 0;

            while (arr[i] > 0) {
                sum += arr[i] % 10;
                arr[i] /= 10;
            }

            if (minEle > sum) {
                minEle = sum;
            }
        }

        return minEle;
    }
};
