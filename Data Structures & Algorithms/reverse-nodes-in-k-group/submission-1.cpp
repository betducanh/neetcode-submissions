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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* traversal = head;
        int count = 0;

        while (traversal != nullptr && count < k) {
            traversal = traversal->next;
            count++;
        }

        if (count < k) return head;

        // this is to divide into groups of k elements
        ListNode* nextHead = traversal;

        // where i actually reverse the nodes
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur != nextHead) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        
        head->next = reverseKGroup(cur, k);
        head = prev;
        return head;
    }
};
