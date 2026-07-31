// Problem: Maximum Product of Two Elements in an Integer
// Difficulty: Easy
// Approach: Find Two Largest Digits
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int maxProduct(int n) {

        int largestDigit = 0;
        int secondLargestDigit = 0;

        while (n > 0) {

            int currentDigit = n % 10;

            if (currentDigit >= largestDigit) {
                secondLargestDigit = largestDigit;
                largestDigit = currentDigit;
            }
            else if (currentDigit > secondLargestDigit) {
                secondLargestDigit = currentDigit;
            }

            n /= 10;
        }

        return largestDigit * secondLargestDigit;
    }
};
