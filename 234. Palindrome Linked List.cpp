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
        ListNode* cur = start, *pre = NULL, * next;
        
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

    }
    
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head, * fast = head, * mid = NULL;
        
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        if (fast->next) {
            mid = slow->next;
            fast = fast->next;
        } else {
            mid = slow;
        }
        
        re(mid);
        slow = head;
        
        while (fast) {
            if (slow->val != fast->val) return false;
            slow = slow->next;
            fast = fast->next;
        }
        
        return true;
        
    }
};