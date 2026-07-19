// Problem: Middle of the Linked List
// Difficulty: Easy
// Approach: Slow and Fast Pointers
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};
