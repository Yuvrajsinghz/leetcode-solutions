// Problem: Odd Even Linked List
// Difficulty: Medium
// Approach: Linked List Pointer Manipulation
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if (!head || !head->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even && even->next) {

            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
