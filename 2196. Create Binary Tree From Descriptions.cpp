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
    unordered_map<int, TreeNode*> node_map;
    unordered_map<int, bool> has_parent;
    void check_exist(int i) {
        if (node_map.count(i) == 0) {
            node_map[i] = new TreeNode(i);
            has_parent[i] = false;
        }
    }


public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        
        for (auto &a: descriptions) {
            int parent = a[0];
            int child = a[1];
            check_exist(parent);
            check_exist(child);
            has_parent[child] = true;
            if (a[2]) {
                node_map[parent]->left = node_map[child];
            } else {
                node_map[parent]->right = node_map[child];
            }
        }

        for (auto &a: has_parent) {
            if (!a.second) {
                return node_map[a.first];
            }
        }

        return NULL;
    }
};