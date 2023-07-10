class Solution {
public:
     static int minSubDepth(TreeNode *root) {
        if (!root) {
            return 10001;
        }
        if (!root->left && !root->right) {
            return 1;
        }
        int result = std::min(minSubDepth(root->left),
            minSubDepth(root->right)) + 1;
        root->left = nullptr;
        root->right = nullptr;   
        return result;
    }

    static int minDepth(TreeNode* root) {
        std::ios_base::sync_with_stdio(false);
        return !root ? 0 : minSubDepth(root);
    }
};