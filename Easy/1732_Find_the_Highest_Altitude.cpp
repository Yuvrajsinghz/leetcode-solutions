// Problem: Find the Highest Altitude
// Difficulty: Easy
// Approach: Prefix Sum Tracking
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currAltitude = 0;
        int maxAltitude = 0;

        for (int g : gain) {
            currAltitude += g;
            maxAltitude = max(maxAltitude, currAltitude);
        }

        return maxAltitude;
    }
};
