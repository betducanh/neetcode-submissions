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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carrying = 0;

        while (l1 || l2 || carrying) {
            int l1Value = l1 ? l1->val : 0;
            int l2Value = l2 ? l2->val : 0;

            int curDigit = l1Value + l2Value + carrying;

            if (curDigit >= 10) {
                carrying = 1;
                curDigit %= 10;
            } else carrying = 0;

            curr->next = new ListNode(curDigit);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;    
        }

        return dummy.next;
    }
};
