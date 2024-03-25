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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        if (!cur) return head;
        ListNode* next = head->next;

        while (next) {
            cur->next = pre;
            pre = cur;
            cur = next;
            next = next->next;
        }
        cur->next = pre;

        return cur;
    }
};