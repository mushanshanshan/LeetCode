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
    ListNode* R(ListNode* pre, ListNode* cur){
        if (cur == NULL){
            return pre;
        }
        
        ListNode* temp = cur->next;
        cur->next = pre;
        
        return R(cur, temp);
    }
    
    
    ListNode* reverseList(ListNode* head) {
        return R(NULL, head);
    }
};