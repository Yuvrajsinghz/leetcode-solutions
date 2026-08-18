// Problem: Stone Game IX
// Difficulty: Medium
// Approach: Math + Counting Remainders
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0, 0, 0};

        for (int x : stones) {
            cnt[x % 3]++;
        }

        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        return abs(cnt[1] - cnt[2]) > 2;
    }
};
