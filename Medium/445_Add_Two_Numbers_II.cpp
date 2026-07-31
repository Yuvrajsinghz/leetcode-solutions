// Problem: Add Two Numbers II
// Difficulty: Medium
// Approach: Reverse Both Lists + Addition + Reverse Result
// Time Complexity: O(n + m)
// Space Complexity: O(max(n, m))

class Solution {
public:
    ListNode* reverse(ListNode* head) {

        ListNode* prev = NULL;

        while (head) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        l1 = reverse(l1);
        l2 = reverse(l2);

        ListNode* dummyHead = new ListNode(0);
        ListNode* currentNode = dummyHead;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int total = carry;

            if (l1 != NULL) {
                total += l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                total += l2->val;
                l2 = l2->next;
            }

            carry = total / 10;

            currentNode->next = new ListNode(total % 10);
            currentNode = currentNode->next;
        }

        return reverse(dummyHead->next);
    }
};
