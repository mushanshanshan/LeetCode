/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto endA = headA;
        auto endB = headB;
        int lenA = 0;
        int lenB = 0;
        while (endA->next != NULL){
            endA = endA->next;
            lenA++;
        }
        
        while (endB->next != NULL){
            endB = endB->next;
            lenB++;
        }
        
        if (lenB>lenA){
            swap (lenA, lenB);
            swap (headA, headB);
            
        }
        
        endA = headA;
        endB = headB;
        
        for (int i=0; i<(lenA-lenB); i++){
            endA = endA->next;
        }
        
        while (endA != NULL){
            if (endA == endB) {
                return endA;
            }
            
            endA = endA->next;
            endB = endB->next;
            
        }
        return NULL;
    }
};