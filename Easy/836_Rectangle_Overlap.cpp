// Problem: Rectangle Overlap
// Difficulty: Easy
// Link: https://leetcode.com/problems/rectangle-overlap/
// Approach: Check whether the intersection has positive width and height.
// Time Complexity: O(1)
// Space Complexity: O(1)

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return rec1[0] < rec2[2] &&
               rec2[0] < rec1[2] &&
               rec1[1] < rec2[3] &&
               rec2[1] < rec1[3];
    }
};