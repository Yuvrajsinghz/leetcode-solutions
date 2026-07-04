// Problem: Largest Number
// Difficulty: Medium
// Approach: Custom Sorting
// Time Complexity: O(n log n * k)
// Space Complexity: O(n)

class Solution {
public:
    static bool cmp(int a, int b) {
        string ab = to_string(a) + to_string(b);
        string ba = to_string(b) + to_string(a);

        return ab > ba;
    }

    string largestNumber(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);

        if (arr[0] == 0) {
            return "0";
        }

        string ans = "";

        for (int num : arr) {
            ans += to_string(num);
        }

        return ans;
    }
};
