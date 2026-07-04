// Problem: H-Index II
// Difficulty: Medium
// Approach: Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();

        int start = 0;
        int end = n - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (citations[mid] == n - mid) {
                return n - mid;
            }
            else if (citations[mid] < n - mid) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return n - start;
    }
};
