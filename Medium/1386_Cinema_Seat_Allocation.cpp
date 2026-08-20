// Problem: Cinema Seat Allocation
// Difficulty: Medium
// Approach: Hash Map + Greedy
// Time Complexity: O(m)
// Space Complexity: O(m)
//
// m = reservedSeats.size()

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, set<int>> mp;

        for (auto& seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        // Rows without reservations can fit 2 families
        int ans = (n - mp.size()) * 2;

        for (auto& [row, seats] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // Seats 2-5
            for (int s = 2; s <= 5; s++) {
                if (seats.count(s)) {
                    left = false;
                }
            }

            // Seats 4-7
            for (int s = 4; s <= 7; s++) {
                if (seats.count(s)) {
                    middle = false;
                }
            }

            // Seats 6-9
            for (int s = 6; s <= 9; s++) {
                if (seats.count(s)) {
                    right = false;
                }
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};
