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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int l = 0, cl = 0, mn = 0;
        ListNode *cur = head, *pre = NULL;
        vector<ListNode*> res(k, nullptr);

        while (cur){
            cur = cur->next;
            l++;
        }

        if (!l) return res;

        mn = l % k;
        l = l / k;
        cur = head;

        for (int i=0; i<k; i++){
            res[i] = cur;;
            for (int k=0; k<l + (i < mn); k++){

                pre = cur;
                cur = cur->next;
            }
            pre->next = NULL;
        }

        return res;
    }
};