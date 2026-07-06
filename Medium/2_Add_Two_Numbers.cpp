// Problem: Add Two Numbers
// Difficulty: Medium
// Approach: Linked List Simulation
// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m))

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* firstList, ListNode* secondList) {

        ListNode* dummyHead = new ListNode(0);
        ListNode* currentNode = dummyHead;

        int carry = 0;

        while (firstList != NULL || secondList != NULL || carry != 0) {

            int total = carry;

            if (firstList != NULL) {
                total += firstList->val;
                firstList = firstList->next;
            }

            if (secondList != NULL) {
                total += secondList->val;
                secondList = secondList->next;
            }

            carry = total / 10;

            currentNode->next = new ListNode(total % 10);
            currentNode = currentNode->next;
        }

        return dummyHead->next;
    }
};
