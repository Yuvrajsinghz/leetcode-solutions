// Problem: 1352. Product of the Last K Numbers
// Difficulty: Medium
// Approach: Prefix Product
// Time Complexity: O(1) for add() and getProduct()
// Space Complexity: O(n)

class ProductOfNumbers {
private:
    vector<int> prefix;

public:
    ProductOfNumbers() {
        // Initialize prefix with 1 as the multiplication identity.
        prefix.push_back(1);
    }

    void add(int num) {
        if (num == 0) {
            // Reset prefix products when zero is encountered.
            prefix.clear();
            prefix.push_back(1);
        } 
        else {
            // Store the cumulative product since the last zero.
            prefix.push_back(prefix.back() * num);
        }
    }

    int getProduct(int k) {
        int n = prefix.size();

        // If k is greater than or equal to n, the range contains zero.
        if (k >= n)
            return 0;

        // Calculate the product of the last k numbers using prefix division.
        return prefix[n - 1] / prefix[n - k - 1];
    }
};
