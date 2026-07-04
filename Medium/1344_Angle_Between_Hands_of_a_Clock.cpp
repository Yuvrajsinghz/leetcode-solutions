// Problem: Angle Between Hands of a Clock
// Difficulty: Medium
// Approach: Math (Angle Calculation)
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minAngle = minutes * 6;
        double hourAngle = hour * 30 + minutes * 0.5;

        double angle = abs(hourAngle - minAngle);

        angle = min(angle, 360 - angle);

        return angle;
    }
};
