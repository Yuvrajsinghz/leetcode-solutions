// Problem: Remove Duplicates from Sorted List II
// Difficulty: Medium
// Approach: Dummy Node + Two Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* curr = head;

        while (curr) {

            if (curr->next && curr->val == curr->next->val) {

                while (curr->next &&
                       curr->val == curr->next->val) {
                    curr = curr->next;
                }

                prev->next = curr->next;
            }
            else {
                prev = prev->next;
            }

            curr = curr->next;
        }

        return dummy.next;
    }
};
