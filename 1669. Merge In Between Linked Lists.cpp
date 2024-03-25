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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* dummy = new ListNode(0, list1);
        ListNode* pre = dummy;
        ListNode* end = pre;

        for (int i=0; i<a; i++) {
            pre = pre->next;
        }

        for (int i=0; i<b+2; i++) {
            end = end->next;
        }

        pre->next = list2;
        while (pre->next) pre = pre->next;
        pre->next = end;

        return dummy->next;
    }
};