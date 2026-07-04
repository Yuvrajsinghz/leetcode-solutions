// Problem: Destroying Asteroids
// Difficulty: Medium
// Approach: Greedy + Sorting
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());

        long long currentMass = mass;

        for (int asteroid : asteroids) {
            if (currentMass >= asteroid) {
                currentMass += asteroid;
            }
            else {
                return false;
            }
        }

        return true;
    }
};
