// Problem: Gas Station
// Difficulty: Medium
// Approach: Greedy
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

        int start = 0, totalFuel = 0, tank = 0;

        for (int i = 0; i < gas.size(); i++) {

            int difference = gas[i] - cost[i];

            totalFuel += difference;
            tank += difference;

            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }

        return (totalFuel >= 0) ? start : -1;
    }
};
