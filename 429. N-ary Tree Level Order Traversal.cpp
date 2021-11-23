/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        Node* tnode;
        queue<Node*> q;
        int qsize, tsize;
        
        if (root != NULL) q.push(root);
        
        while (!q.empty()){
            vector<int> v;
            qsize = q.size();
            
            for (int i=0; i< qsize; i++){
                tnode = q.front();
                q.pop();
                tsize = tnode->children.size();
                
                for (int j=0; j<tsize; j++){
                    if (tnode->children[j] != NULL) q.push(tnode->children[j]);
                }
                
                v.push_back(tnode->val);

            }
            res.push_back(v);

        }
        return res;
    }
};