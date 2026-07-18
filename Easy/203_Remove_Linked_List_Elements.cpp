// Problem: Remove Linked List Elements
// Difficulty: Easy
// Approach: Dummy Node + Iterative Traversal
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = &dummy;

        while (curr->next) {

            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};
