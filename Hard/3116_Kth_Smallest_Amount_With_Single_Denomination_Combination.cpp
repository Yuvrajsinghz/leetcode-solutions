// Problem: Kth Smallest Amount With Single Denomination
// Link: https://leetcode.com/problems/kth-smallest-amount-with-single-denomination/
// Difficulty: Hard
// Approach: Binary Search + Inclusion-Exclusion + Bitmasking + LCM
// Time Complexity: O(2^n * n + 2^n * log(k * min(coins)))
// Space Complexity: O(2^n)
class Solution {
public:

    long long findKthSmallest(vector<int>& coins, int k) {

        // Sort coins to make the smallest coin easily accessible.
        sort(coins.begin(), coins.end());

        int n = coins.size();
        int m = 1 << n;  // Total number of subsets.

        // Binary search range.
        long long l = k;
        long long r = (long long)coins[0] * k + 1;

        // Precompute LCM and number of selected coins
        // for every possible subset.
        vector<int> bitCount(m, 0);
        vector<long long> lcm(m, 0);

        for (int mask = 1; mask < m; mask++) {

            long long curLcm = 1;

            for (int i = 0; i < n; i++) {

                // Check if the i-th coin is included in this subset.
                if (((mask >> i) & 1) == 1) {

                    long long g = gcd(curLcm, (long long)coins[i]);
                    long long tmp = curLcm / g;

                    // Prevent LCM from overflowing or becoming
                    // larger than the binary search range.
                    if (tmp <= r / coins[i]) {
                        curLcm = tmp * coins[i];
                    }
                    else {
                        curLcm = r + 1;
                        break;
                    }

                    bitCount[mask]++;
                }
            }

            lcm[mask] = curLcm;
        }

        // Binary search for the smallest number
        // having at least k valid multiples.
        while (l < r) {

            long long x = l + (r - l) / 2;

            if (count(x, m, lcm, bitCount) >= k) {
                r = x;
            }
            else {
                l = x + 1;
            }
        }

        return l;
    }

private:

    // Counts how many positive integers <= x
    // are divisible by at least one coin.
    //
    // Inclusion-Exclusion Principle:
    // Odd number of selected coins  -> add
    // Even number of selected coins -> subtract
    long long count(long long x,
                    int m,
                    vector<long long>& lcm,
                    vector<int>& bitCount) {

        long long res = 0;

        for (int mask = 1; mask < m; mask++) {

            // This subset contributes nothing if its LCM > x.
            if (lcm[mask] > x)
                continue;

            if ((bitCount[mask] & 1) == 1) {
                res += x / lcm[mask];
            }
            else {
                res -= x / lcm[mask];
            }
        }

        return res;
    }

    // Calculates Greatest Common Divisor using Euclidean Algorithm.
    long long gcd(long long a, long long b) {

        while (b != 0) {

            long long t = b;
            b = a % b;
            a = t;
        }

        return a;
    }
};
