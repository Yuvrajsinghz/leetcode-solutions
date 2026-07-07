// Problem: Sum and Multiply
// Difficulty: Easy
// Approach: Digit Extraction
// Time Complexity: O(d)
// Space Complexity: O(1)

class Solution {
public:
    long long sumAndMultiply(int n) {
        long long digitSum = 0;
        long long num = 0;
        long long i = 1;

        while (n != 0) {
            int temp = n % 10;

            if (temp != 0) {
                digitSum += temp;
                num += i * temp;
                i *= 10;
            }

            n /= 10;
        }

        return 1LL * digitSum * num;
    }
};
