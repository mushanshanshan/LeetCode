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
        bool in = false;
        ListNode *res = new ListNode(0);
        ListNode *cur1 = l1, *cur2 = l2, *cur = res;
        int s;
        
        while (cur1 || cur2) {
            if (!cur1) {
                s = cur2->val;
                cur2 = cur2->next;
            } else if (!cur2) {
                s = cur1->val;
                cur1 = cur1->next;
            } else {
                s = cur1->val + cur2->val;
                cur2 = cur2->next;
                cur1 = cur1->next;
            }
            
            if (in) {
                s++;
                in = false;
            }
            
            if (s > 9) {
                in = true;
                s -= 10;
            }
            cur->next = new ListNode(s);
            cur = cur->next;
        }
        
        if (in) {
            cur->next = new ListNode(1);
        }
        
        return res->next;
    }
};