// Problem: Remove Duplicates from Sorted List
// Difficulty: Easy
// Approach: Iterative Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;

        while (temp != NULL && temp->next != NULL) {

            if (temp->val == temp->next->val) {
                temp->next = temp->next->next;
            }
            else {
                temp = temp->next;
            }
        }

        return head;
    }
};
