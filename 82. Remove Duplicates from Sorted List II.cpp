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
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        int duval = -101;
        
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        
        while (cur->next) {
            if (cur->val == cur->next->val) duval = cur->val;
            if (cur->val == duval) {
                cur = cur->next;
                pre->next = cur;
            } else {
                pre = cur;
                cur = cur->next;
            }
        }
        
        if (cur->val == duval) pre->next = cur->next;
        
        return dummy->next;
    }
};