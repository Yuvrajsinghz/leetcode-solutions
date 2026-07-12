// Problem: Rotate List
// Difficulty: Medium
// Approach: Circular Linked List
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int n) {

        if (head == nullptr || head->next == nullptr || n == 0)
            return head;

        int len = 1;
        ListNode* tail = head;

        while (tail->next != nullptr) {
            tail = tail->next;
            len++;
        }

        n %= len;

        if (n == 0) {
            return head;
        }

        tail->next = head;

        ListNode* newTail = head;

        for (int i = 0; i < len - n - 1; i++) {
            newTail = newTail->next;
        }

        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
