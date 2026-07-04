// Problem: Process String With Queries (Kth Character After Operations)
// Difficulty: Hard
// Approach: Reverse Simulation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long length = 0;

        for (int i = 0; i < n; i++) {

            char ch = s[i];

            if (islower(ch)) {
                length++;
            }
            else if (ch == '*') {
                length = max(0LL, length - 1);
            }
            else if (ch == '#') {
                length *= 2;
            }
            else if (ch == '%') {
                continue;
            }
        }

        if (k >= length) return '.';

        for (int i = n - 1; i >= 0; i--) {

            char ch = s[i];

            if (islower(ch)) {
                length--;

                if (k == length) {
                    return ch;
                }
            }
            else if (ch == '#') {
                length /= 2;

                if (k >= length) {
                    k -= length;
                }
            }
            else if (ch == '%') {
                k = length - 1 - k;
            }
            else if (ch == '*') {
                length++;
            }
        }

        return '.';
    }
};
