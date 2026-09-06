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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> ourList;

        for (int i = 0; i < lists.size(); i++) {
            while (lists[i] != nullptr) {
                ourList.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        sort(ourList.begin(), ourList.end());

        ListNode* bob = new ListNode();
        ListNode* cur = bob;

        for (int data : ourList) {
            cur->next = new ListNode(data);
            cur = cur->next;
        }

        return bob->next;
    }
};
