// Problem: Grumpy Bookstore Owner
// Difficulty: Medium
// Approach: Sliding Window
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfiedCustomer = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 0) {
                satisfiedCustomer += customers[i];
            }
        }

        int extraCustomer = 0;
        int bonusCustomer = 0;

        for (int i = 0; i < customers.size(); i++) {
            if (grumpy[i] == 1) {
                extraCustomer += customers[i];
            }

            if (i >= minutes && grumpy[i - minutes] == 1) {
                extraCustomer -= customers[i - minutes];
            }

            bonusCustomer = max(bonusCustomer, extraCustomer);
        }

        return satisfiedCustomer + bonusCustomer;
    }
};
