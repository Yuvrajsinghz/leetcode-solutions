// Problem: Intersection of Two Linked Lists
// Difficulty: Easy
// Approach: Two Pointers
// Time Complexity: O(m + n)
// Space Complexity: O(1)

class Solution {
public:
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {

        ListNode* pA = headA;
        ListNode* pB = headB;

        while (pA != pB) {

            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};
