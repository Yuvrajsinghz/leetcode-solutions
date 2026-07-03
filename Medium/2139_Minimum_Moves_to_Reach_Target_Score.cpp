// Problem: Minimum Moves to Reach Target Score
// Difficulty: Medium
// Link: https://leetcode.com/problems/minimum-moves-to-reach-target-score/
// Approach: Reverse Greedy
// Time Complexity: O(log target)
// Space Complexity: O(1)

class Solution {
public:
    int minMoves(int target, int maxDoubles) {

        int x = target;
        int step = 0;

        while (x != 1 && maxDoubles != 0) {

            if (x % 2 == 0) {
                x /= 2;
                maxDoubles--;
            }
            else {
                x -= 1;
            }

            step++;
        }

        return step + x - 1;
    }
};
