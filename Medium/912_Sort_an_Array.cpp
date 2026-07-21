// Problem: Sort an Array
// Difficulty: Medium
// Approach: Merge Sort
// Time Complexity: O(n log n)
// Space Complexity: O(n)

class Solution {
public:

    void mergeArr(vector<int>& nums, int start, int mid, int end) {

        vector<int> temp;

        int i = start;
        int j = mid + 1;

        while (i <= mid && j <= end) {

            if (nums[i] < nums[j]) {
                temp.push_back(nums[i]);
                i++;
            }
            else {
                temp.push_back(nums[j]);
                j++;
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i]);
            i++;
        }

        while (j <= end) {
            temp.push_back(nums[j]);
            j++;
        }

        for (int idx = 0; idx < temp.size(); idx++) {
            nums[start + idx] = temp[idx];
        }
    }

    void divideArr(vector<int>& nums, int start, int end) {

        if (start >= end)
            return;

        int mid = start + (end - start) / 2;

        divideArr(nums, start, mid);
        divideArr(nums, mid + 1, end);

        mergeArr(nums, start, mid, end);
    }

    vector<int> sortArray(vector<int>& nums) {

        int n = nums.size();

        divideArr(nums, 0, n - 1);

        return nums;
    }
};
