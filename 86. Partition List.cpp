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
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* left = dummy, * right = dummy->next, * cur, * pre;
        
        while (right) {
            if (right->val >= x) break;
            left = left->next;
            right = right->next;
        }
    
        if (!right) return head;
        
        pre = right;
        cur = right->next;
        
        while (cur) {
            if (cur->val < x) {
                left->next = cur;
                left = cur;
                pre->next = cur->next;
                cur = cur->next;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        
        left->next = right;
        
        return dummy->next;
    }
};