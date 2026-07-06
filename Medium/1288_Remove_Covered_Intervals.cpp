// Problem: Remove Covered Intervals
// Difficulty: Medium
// Approach: Sorting + Greedy
// Time Complexity: O(n log n)
// Space Complexity: O(1)

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int count = 0;
        int maxIntr = -1;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];

                 return a[0] < b[0];
             });

        for (auto& interval : intervals) {
            if (interval[1] > maxIntr) {
                count++;
                maxIntr = interval[1];
            }
        }

        return count;
    }
};
