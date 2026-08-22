// Problem: Check Divisibility by Digit Sum and Product
// Difficulty: Easy
// Approach: Digit Extraction
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    bool checkDivisibility(int num) {
        int n = num;

        int digit = 0;
        int digSum = 0;
        int digPro = 1;

        while (n != 0) {
            digit = n % 10;

            digSum += digit;
            digPro *= digit;

            n /= 10;
        }

        int div = digSum + digPro;

        return num % div == 0;
    }
};
