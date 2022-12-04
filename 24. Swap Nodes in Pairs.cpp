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
    ListNode* swapPairs(ListNode* head) {
        ListNode* S = new ListNode(0, head);
        ListNode* cur = S;
        
        while (cur->next != NULL && cur->next->next != NULL){
            ListNode* _t = cur->next->next->next;
            ListNode* _s = cur->next->next;
            cur->next->next->next = cur->next;
            cur->next->next = _t;
            cur->next = _s;
            
            cur = cur->next->next;
        }
        return S->next;
        
    }
};