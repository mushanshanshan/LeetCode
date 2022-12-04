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
    void re(ListNode* start) {
        ListNode* cur = start, *pre = NULL, *next;
        
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        
    }
    
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head, *mid;
        ListNode* snext, *fnext;
        
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        if (fast->next) fast = fast->next;
        mid = slow->next;
        re(mid);
        
        slow->next = NULL;
        slow = head;
        mid = fast;
        
        while (fast) {
            snext = slow->next;
            fnext = fast->next;
            slow->next = fast;
            fast->next = snext;
            slow = snext;
            fast = fnext;
        }
        
    }
};