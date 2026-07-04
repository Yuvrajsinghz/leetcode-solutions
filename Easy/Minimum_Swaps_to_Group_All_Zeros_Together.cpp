// Problem: Minimum Swaps to Group All Zeros Together
// Difficulty: Easy
// Approach: Counting
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int minimumSwaps(vector<int>& arr) {
        int size = arr.size();
        int zero = 0;

        for (int num : arr) {
            if (num == 0)
                zero++;
        }

        int answer = 0;

        for (int i = size - zero; i < size; i++) {
            if (arr[i] != 0)
                answer++;
        }

        return answer;
    }
};
