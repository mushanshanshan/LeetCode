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
    ListNode* s;
    
    Solution(ListNode* head) {
        s = head;
    }
    
    int getRandom() {
        int rval = s->val, count = 1;
        ListNode* cur = s->next;
        
        while (cur != NULL) {
            count++;
            if (rand() % count == 0) {
                rval = cur->val;
            }
            cur = cur->next;
        }
        
        return rval;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */