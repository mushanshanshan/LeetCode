/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        Node* tnode;
        
        if (root != NULL) q.push(root);
        while(!q.empty()){
            int qsize = q.size();
            
            for (int i=0; i<qsize; i++){
                tnode = q.front();
                q.pop();
                if (i == qsize -1){
                    tnode->next =NULL;
                } else {
                    tnode->next = q.front();
                }
                
                if (tnode->left != NULL) q.push(tnode->left);
                if (tnode->right != NULL) q.push(tnode->right);  
            }

        }
        return root;
        
        
        
    }
};