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
public:
    
    TreeNode* tr(vector<int>& nums, int left, int right){
        if (left >= right) {
            return NULL;
        }
        
        
        
        int maxindex = left;
        int temp = nums[left];
        for(int i= maxindex+1; i < right; i++){
            if (nums[i] > temp) {
                temp = nums[i];
                maxindex = i;
            }
        }
        
        TreeNode* node = new TreeNode(temp);
        
        node->left = tr(nums, left, maxindex);
        node->right = tr(nums, maxindex+1, right);
        
        return node;
        
        
        
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = tr(nums, 0, nums.size());
        
        return root;
    }
};