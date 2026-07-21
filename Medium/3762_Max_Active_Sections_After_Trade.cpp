// Problem: Max Active Sections After Trade
// Difficulty: Medium
// Approach: Count 1-blocks and Track Adjacent 0-block Gains
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int totalOnes = 0;
        int previousZero = INT_MIN;
        int maxGain = 0;

        int n = s.size();

        for (int i = 0; i < n; ) {

            int j = i;

            while (j < n && s[j] == s[i]) {
                j++;
            }

            int blockLength = j - i;

            if (s[i] == '1') {
                totalOnes += blockLength;
            }
            else {
                maxGain = max(maxGain, previousZero + blockLength);
                previousZero = blockLength;
            }

            i = j;
        }

        return totalOnes + maxGain;
    }
};
