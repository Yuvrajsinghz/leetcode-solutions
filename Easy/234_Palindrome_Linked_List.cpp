// Problem: Palindrome Linked List
// Difficulty: Easy
// Approach: Find Middle + Reverse Second Half + Compare
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    bool isPalindrome(ListNode* head) {

        if (!head || !head->next) {
            return true;
        }

        // Find middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* curr = slow;

        while (curr) {

            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        // Compare both halves
        ListNode* first = head;
        ListNode* second = prev;

        while (second) {

            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
