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
    vector<int> startPath, destPath;
    bool findPath(TreeNode* root, int target, vector<int>& path) {
        if (!root) return false;
        if (root->val == target) return true;

        path.push_back(0); 
        if (findPath(root->left, target, path)) return true;
        path.pop_back(); 

        path.push_back(1);
        if (findPath(root->right, target, path)) return true;
        path.pop_back();

        return false;
    }

public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        findPath(root, startValue, startPath);
        findPath(root, destValue, destPath);

        int commonLength = 0;
        while (commonLength < startPath.size() && commonLength < destPath.size() && startPath[commonLength] == destPath[commonLength]) {
            commonLength++;
        }

        string res;
        for (int i = commonLength; i < startPath.size(); i++) {
            res += 'U';
        }
        for (int i = commonLength; i < destPath.size(); i++) {
            res += (destPath[i] == 0 ? 'L' : 'R'); 
        }

        return res;
    }
};