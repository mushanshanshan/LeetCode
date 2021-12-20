/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* tr(ListNode* head, ListNode* end = NULL) {
        if (head == end) return NULL;
        
        ListNode* slow = head, *fast = head;
        
        while (fast!=end && fast->next!=end) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        TreeNode* node = new TreeNode(slow->val);
        
        node->left = tr(head, slow);
        node->right = tr(slow->next, end);
        
        return node;
        
        
    }
    
    
    TreeNode* sortedListToBST(ListNode* head) {
        return tr(head, NULL);
    }
};