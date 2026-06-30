// Problem: Linked List Cycle II
// Difficulty: Medium
// Link: https://leetcode.com/problems/linked-list-cycle-ii/
// Approach: Floyd's Cycle Detection (Tortoise and Hare)
// Time Complexity: O(n)
// Space Complexity: O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        // Phase 1: Detect cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {

                // Phase 2: Find cycle start
                ListNode* temp = head;

                while (temp != slow) {
                    temp = temp->next;
                    slow = slow->next;
                }

                return temp;
            }
        }

        return NULL;
    }
};
