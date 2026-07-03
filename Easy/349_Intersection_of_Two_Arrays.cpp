// Problem: Intersection of Two Arrays
// Difficulty: Easy
// Link: https://leetcode.com/problems/intersection-of-two-arrays/
// Approach: Hash Set
// Time Complexity: O(n + m) Average
// Space Complexity: O(n)

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s(
            nums1.begin(),
            nums1.end()
        );

        vector<int> ans;

        for (int x : nums2) {

            if (s.count(x)) {

                ans.push_back(x);

                s.erase(x);
            }
        }

        return ans;
    }
};
