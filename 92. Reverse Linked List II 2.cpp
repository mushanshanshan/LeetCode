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
    ListNode* reverseBetween(ListNode* head, int left_idx, int right_idx) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *pre_left = dummy, *last_right = nullptr, *left = nullptr, *right = dummy;
        for (int i=0; i<left_idx-1; i++) {
            pre_left = pre_left->next;
        }
        left = pre_left->next;

        for (int i=0; i<right_idx; i++) {
            right = right->next;
        }
        last_right = right->next;

        ListNode *cur = left, *pre = nullptr, *temp = nullptr;
        while (cur != last_right) {
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        left->next = last_right;
        pre_left->next = right;

        left = dummy->next;
        delete dummy; 

        return left;
    }
};