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
    
    struct Comp { 
        bool operator() (ListNode* l1, ListNode* l2) { 
            return l1->val > l2->val;
        }
    };
    
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Comp> q;
        ListNode* s = new ListNode();
        ListNode* cur = s;
        
        for (ListNode* l : lists) {
            if (l != NULL) q.push(l);
        }
        
        while(!q.empty()) {
            cur->next = q.top();
            if (q.top()->next != NULL) q.push(q.top()->next);
            q.pop();
            cur = cur->next;
        }
        return s->next;
    }
};