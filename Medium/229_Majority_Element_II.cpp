// Problem: Majority Element II
// Difficulty: Medium
// Approach: Boyer-Moore Voting Algorithm
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, candidate2 = 1;
        int count1 = 0, count2 = 0;
        int freq1 = 0, freq2 = 0;

        vector<int> result;

        for (int num : nums) {
            if (num == candidate1) {
                count1++;
            }
            else if (num == candidate2) {
                count2++;
            }
            else if (count1 == 0) {
                candidate1 = num;
                count1 = 1;
            }
            else if (count2 == 0) {
                candidate2 = num;
                count2 = 1;
            }
            else {
                count1--;
                count2--;
            }
        }

        for (int num : nums) {
            if (candidate1 == num) {
                freq1++;
            }
            else if (candidate2 == num) {
                freq2++;
            }
        }

        if (freq2 > nums.size() / 3 && candidate1 != candidate2) {
            result.push_back(candidate2);
        }

        if (freq1 > nums.size() / 3) {
            result.push_back(candidate1);
        }

        return result;
    }
};
