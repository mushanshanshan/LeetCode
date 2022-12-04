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
        unordered_map<Node*, Node*> dict;
        
        Node* dummy = new Node(0);
        Node* cur = head,* copycur = dummy;
        
        while (cur) {
            copycur->next = new Node(cur->val);
            copycur = copycur->next;
            dict[cur] = copycur;
            cur = cur->next;
        }
        
        cur = head, copycur = dummy->next;
        
        while (cur) {
            if (cur->random) {
                copycur->random = dict[cur->random];
            }
            cur = cur->next;
            copycur = copycur->next;
        }
        
        return dummy->next;
    }
};