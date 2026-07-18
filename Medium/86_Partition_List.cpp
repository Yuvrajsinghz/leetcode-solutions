// Problem: Partition List
// Difficulty: Medium
// Approach: Two Separate Linked Lists
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {

        ListNode lessHead(0);
        ListNode greHead(0);

        ListNode* lessThen = &lessHead;
        ListNode* greThen = &greHead;

        while (head != nullptr) {

            if (head->val < x) {
                lessThen->next = head;
                lessThen = lessThen->next;
            }
            else {
                greThen->next = head;
                greThen = greThen->next;
            }

            head = head->next;
        }

        greThen->next = nullptr;
        lessThen->next = greHead.next;

        return lessHead.next;
    }
};
