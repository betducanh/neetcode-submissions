class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* firstHalf = head;
        ListNode* secondHalf = slow->next;
        slow->next = nullptr;

        ListNode* prev = nullptr;
        ListNode* cur = secondHalf;

        while (cur) {
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }

        secondHalf = prev;

        while(secondHalf) {
            ListNode* temp1 = firstHalf->next;
            ListNode* temp2 = secondHalf->next;

            firstHalf->next = secondHalf;
            secondHalf->next = temp1;

            firstHalf = temp1;
            secondHalf = temp2;
        }
    }
};
