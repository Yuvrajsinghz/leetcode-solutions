// Problem: Merge Two Sorted Lists
// Difficulty: Easy
// Approach: Iterative Linked List Merge
// Time Complexity: O(n + m)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL)
            return list2;

        if (list2 == NULL)
            return list1;

        ListNode* temp = new ListNode(0);
        ListNode* ans = temp;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                ans = ans->next = list1;
                list1 = list1->next;
            }
            else {
                ans = ans->next = list2;
                list2 = list2->next;
            }
        }

        if (list1)
            ans->next = list1;
        else
            ans->next = list2;

        return temp->next;
    }
};
