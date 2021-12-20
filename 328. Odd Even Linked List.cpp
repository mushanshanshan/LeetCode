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
        if (head == NULL || head->next == NULL) return head;
        ListNode* end = head, *start = head, *temp = NULL, *flag;
        while(end->next && end->next->next) end=end->next->next;
        if (end->next != NULL) temp = end->next;
        flag = end;
        
        while (start != flag) {
            end->next = start->next;
            start->next = start->next->next;
            start = start->next;

            end = end->next;
        }
        if (temp) {
            end->next = temp;
            end = end->next;
        }
        end->next = NULL;
        return head;
    }
};