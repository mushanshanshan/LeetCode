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

        auto cmp = [](ListNode* a, ListNode* b) {return a->val > b->val;};
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> q(cmp);
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        for (auto a: lists) {
            if (a) q.push(a);
        }

        while (!q.empty()) {
            ListNode* top = q.top();
            q.pop();
            cur->next = top;
            cur = cur->next;

            if (top->next) q.push(top->next);
        }
        cur->next = NULL;

        return dummy->next;
    }
};