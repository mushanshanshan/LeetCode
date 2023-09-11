/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return head;

        Node *cur = head, *temp_next, *res;

        while (cur) {
            temp_next = cur->next;
            cur->next = new Node(cur->val);
            cur->next->next = temp_next;
            cur = temp_next;
        }

        cur = head;

        while (cur) {
            if (cur->random) {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }   

        cur = head;
        res = cur->next;

        while (cur) {
            temp_next = cur->next->next;
            if (temp_next) cur->next->next = temp_next->next;
            cur->next = temp_next;
            cur = temp_next;
        }

        return res;
    }
};