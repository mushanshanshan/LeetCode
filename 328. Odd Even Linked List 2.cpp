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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        
        ListNode dummy = ListNode(0, NULL);
        ListNode *odd = head, *even = &dummy, *temp = NULL, *res = head;

        while (odd->next && odd->next->next) {
            temp = odd->next;
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = temp;
            even = even->next;
        }

        if (odd->next) {
            even->next = odd->next;
            even = even->next;
        }

        even->next = NULL;
        odd->next = dummy.next;
        
        return head;
    }
};