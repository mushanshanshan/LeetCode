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
    void reverse(ListNode* s) {
        ListNode* pre = s, * cur = s->next, * next;
        
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        int count = k;
        ListNode* start = head, *cur = head, *end, *pre;
        ListNode* dummy = new ListNode();
        dummy->next = head;
        pre = dummy;
        
        while (cur) {
            if (count == 1) {
                count = k;
                end = cur;
                cur = cur->next;
                end->next = NULL;
                reverse(start);
                pre->next = end;
                start->next = cur;
                pre = start;
                start = cur;
            } else {
                cur = cur->next;
                count--;
            }
        }
        
        return dummy->next;
    }
};