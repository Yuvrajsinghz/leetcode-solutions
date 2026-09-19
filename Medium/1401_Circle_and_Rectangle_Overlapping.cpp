// Problem: Circle and Rectangle Overlapping
// Difficulty: Medium
// Link: https://leetcode.com/problems/circle-and-rectangle-overlapping/
// Approach: Find the closest point of the rectangle to the circle's center
// and check whether its distance from the center is <= radius.
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));

        int dx = xCenter - closestX;
        int dy = yCenter - closestY;

        return dx * dx + dy * dy <= radius * radius;
    }
};