// Problem: Find the Minimum and Maximum Number of Nodes Between Critical Points
// Difficulty: Medium
// Approach: One Pass Traversal
// Time Complexity: O(n)
// Space Complexity: O(k)   // k = number of critical points

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> criticalPoints;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int pos = 1;

        while (curr->next) {

            // Local minima or local maxima
            if ((prev->val > curr->val &&
                 curr->val < curr->next->val) ||

                (prev->val < curr->val &&
                 curr->val > curr->next->val)) {

                criticalPoints.push_back(pos);
            }

            prev = curr;
            curr = curr->next;
            pos++;
        }

        if (criticalPoints.size() < 2) {
            return {-1, -1};
        }

        int mn = INT_MAX;

        for (int i = 1; i < criticalPoints.size(); i++) {
            mn = min(
                mn,
                criticalPoints[i] - criticalPoints[i - 1]
            );
        }

        int mx =
            criticalPoints.back() -
            criticalPoints.front();

        return {mn, mx};
    }
};
