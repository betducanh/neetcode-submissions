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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;

        while (cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        return prev;
    }

public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev;
        ListNode* after;
        ListNode* beginNode;
        ListNode* endNode;
        ListNode* traversal = dummy;
        for (int i = 0; i <= right; i++) {
            if (i == left-1) prev = traversal;
            if (i == left) beginNode = traversal;
            if (i == right) {
                endNode = traversal;
                after = traversal->next;
                endNode->next = nullptr;
                break;
            }
            traversal = traversal->next;
        }    
        
        prev->next = reverseList(beginNode);
        traversal = dummy;
        while (traversal->next) traversal = traversal->next;
        traversal->next = after;

        return dummy->next;
    }
};