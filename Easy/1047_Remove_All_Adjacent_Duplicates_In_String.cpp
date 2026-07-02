// Problem: Remove All Adjacent Duplicates In String
// Difficulty: Easy
// Link: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
// Approach: Stack Simulation Using String
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    string removeDuplicates(string str) {
        string answer = "";

        for (char ch : str) {

            if (!answer.empty() &&
                answer.back() == ch) {

                answer.pop_back();
            }
            else {
                answer.push_back(ch);
            }
        }

        return answer;
    }
};
