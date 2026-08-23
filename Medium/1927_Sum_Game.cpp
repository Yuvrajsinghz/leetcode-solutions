// Problem: Sum Game
// Difficulty: Medium
// Approach: Math / Game Theory
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int leftSum = 0;
        int rightSum = 0;

        int leftQ = 0;
        int rightQ = 0;

        // Left half
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?') {
                leftQ++;
            } else {
                leftSum += num[i] - '0';
            }
        }

        // Right half
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?') {
                rightQ++;
            } else {
                rightSum += num[i] - '0';
            }
        }

        // Odd number of question marks
        // Alice always wins
        if ((leftQ + rightQ) % 2) {
            return true;
        }

        int diff = leftSum - rightSum;

        return diff != (rightQ - leftQ) * 9 / 2;
    }
};
