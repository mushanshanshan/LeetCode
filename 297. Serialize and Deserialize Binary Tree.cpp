/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize_(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserialize_(iss);
    }
    
private:
    void serialize_(TreeNode* root, ostringstream &oss) {
        if (root) {
            oss << root->val <<" ";
            serialize_(root->left, oss);
            serialize_(root->right, oss);
        } else {
            oss << "# ";
        }
    }
    
    TreeNode* deserialize_(istringstream &iss) {
        string temp;
        iss >> temp;
        if (temp == "#") return nullptr;
        else {
            TreeNode* cur = new TreeNode(stoi(temp));
            cur->left = deserialize_(iss);
            cur->right = deserialize_(iss);
            return cur;
        }
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));