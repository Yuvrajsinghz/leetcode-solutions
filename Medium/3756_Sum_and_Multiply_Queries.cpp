// Problem: Sum and Multiply Queries
// Difficulty: Medium
// Approach: Prefix Sum + Non-Zero Digit Compression
// Time Complexity: O(n + q)
// Space Complexity: O(n)

class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        int q = queries.size();

        vector<int> prefArr;
        vector<int> position(n, -1);
        vector<int> digit;

        prefArr.resize(n + 1, 0);

        for (int i = 0; i < n; i++) {
            prefArr[i + 1] = prefArr[i] + (s[i] - '0');
        }

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                position[i] = digit.size();
                digit.push_back(s[i] - '0');
            }
        }

        int m = digit.size();

        vector<int> leftNonZero(n);
        int last = -1;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0')
                last = i;

            leftNonZero[i] = last;
        }

        vector<int> rightNonZero(n);

        last = -1;

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] != '0')
                last = i;

            rightNonZero[i] = last;
        }

        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        vector<long long> prefixValue(m + 1, 0);

        for (int i = 0; i < m; i++) {
            prefixValue[i + 1] = (prefixValue[i] * 10 + digit[i]) % MOD;
        }

        vector<int> answer;

        for (int i = 0; i < q; i++) {
            int left = queries[i][0];
            int right = queries[i][1];

            long long sum = prefArr[right + 1] - prefArr[left];

            int first = rightNonZero[left];
            int last = leftNonZero[right];

            if (first == -1 || first > right || last == -1 || last < left) {
                answer.push_back(0);
                continue;
            }

            int l = position[first];
            int r = position[last];

            long long value =
                (prefixValue[r + 1] -
                 (prefixValue[l] * pow10[r - l + 1]) % MOD + MOD) % MOD;

            answer.push_back((sum * value) % MOD);
        }

        return answer;
    }
};
