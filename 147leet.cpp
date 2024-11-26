/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        vector<int> a;
        while (head != nullptr) {
            a.push_back(head->val);
            head = head->next;
        }

        sort(a.begin(), a.end());

        if (a.empty()) {
            return nullptr;
        }

        head = new ListNode(a[0]);
        ListNode* mover = head;

        for (int i = 1; i < a.size(); i++) {
            ListNode* temp = new ListNode(a[i]);
            mover->next = temp;
            mover = temp;
        }

        return head;
    }
};
