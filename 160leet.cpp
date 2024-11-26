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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *originalHeadB = headB;
        while (headA != nullptr) {
            headB = originalHeadB; 
            while (headB != nullptr) {
                if (headA == headB) {
                    return headA;
                } else {
                    headB = headB->next;
                }
            }
            headA = headA->next;
        }
        return nullptr;
    }
};
