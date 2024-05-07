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
    ListNode* doubleIt(ListNode* head) {

        ListNode* dummy = new ListNode(0, head);
        ListNode* pre = dummy;

        while (head) {
            if (head->val > 4) {
                pre->val++;
                head->val = head->val * 2 - 10;
            } else {
                head->val = head->val * 2;
            }
            pre = head;
            head = head->next;
        }

        return dummy->val == 0? dummy->next: dummy;
    }
};