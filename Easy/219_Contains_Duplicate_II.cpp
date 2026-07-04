// Problem: Contains Duplicate II
// Difficulty: Easy
// Approach: Hash Map
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        unordered_map<int, int> map;

        for (int i = 0; i < arr.size(); i++) {
            if (map.count(arr[i])) {
                if (i - map[arr[i]] <= k)
                    return true;
            }

            map[arr[i]] = i;
        }

        return false;
    }
};
