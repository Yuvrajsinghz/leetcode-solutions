// Problem: Lexicographically Smallest Palindromic Permutation
// Difficulty: Medium
// Link: https://leetcode.com/problems/
// Approach: Greedily build the first half of the palindrome and ensure the
//            smallest possible completion is lexicographically greater than target.
// Time Complexity: O(n * 26)
// Space Complexity: O(n)

class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        char middle = 0;
        int odd = 0;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1) {
            return "";
        }

        vector<int> halfFreq(26);

        for (int i = 0; i < 26; i++) {
            halfFreq[i] = freq[i] / 2;
        }

        string prefix;

        auto canBuild = [&]() -> bool {
            string left = prefix;

            for (int c = 25; c >= 0; c--) {
                left += string(halfFreq[c], char('a' + c));
            }

            string palindrome = left;

            if (n % 2) {
                palindrome += middle;
            }

            for (int i = (int)left.size() - 1; i >= 0; i--) {
                palindrome += left[i];
            }

            return palindrome > target;
        };

        for (int pos = 0; pos < n / 2; pos++) {
            bool found = false;

            for (int c = 0; c < 26; c++) {
                if (halfFreq[c] == 0) {
                    continue;
                }

                halfFreq[c]--;
                prefix.push_back(char('a' + c));

                if (canBuild()) {
                    found = true;
                    break;
                }

                prefix.pop_back();
                halfFreq[c]++;
            }

            if (!found) {
                return "";
            }
        }

        string answer = prefix;

        if (n % 2) {
            answer += middle;
        }

        for (int i = (int)prefix.size() - 1; i >= 0; i--) {
            answer += prefix[i];
        }

        return answer > target ? answer : "";
    }
};