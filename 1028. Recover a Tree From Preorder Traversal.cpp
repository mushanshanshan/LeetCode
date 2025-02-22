/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        vector<TreeNode*> vec;
    
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            int N = traversal.size();
    
            for (int i=0; i<N;) {
                int level = 0;
                while (traversal[i] == '-') {
                    i++;
                    level++;
                }
    
                int val = 0;
                while (i < N && traversal[i] != '-') {
                    val = val * 10 + (traversal[i++] - '0');
                }
    
                TreeNode* cur_node = new TreeNode(val);
                while (vec.size() > level) vec.pop_back();
                if (vec.size() > 0) {
                    if (vec.back() -> left) vec.back() -> right = cur_node;
                    else vec.back() -> left = cur_node;
                }
                vec.push_back(cur_node);
            }
    
            return vec[0];
        }
    };