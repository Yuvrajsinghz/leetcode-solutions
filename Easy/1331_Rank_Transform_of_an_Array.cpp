// Problem: Rank Transform of an Array
// Difficulty: Easy
// Approach: Sorting + Hash Map
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;
        int n = arr.size();

        sort(temp.begin(), temp.end());

        int rank = 1;
        unordered_map<int, int> mp;

        for (int x : temp) {
            if (mp.find(x) == mp.end()) {
                mp[x] = rank++;
            }
        }

        for (int i = 0; i < n; i++) {
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};
