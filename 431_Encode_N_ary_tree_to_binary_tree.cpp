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
    // Encodes an n-ary tree to a binary tree.
    TreeNode* encode(Node* root) {
        if (!root)
            return nullptr;
        TreeNode* ans = new TreeNode(root->val);
        if (!root->children.empty()) {
            ans->left = encode(root->children[0]);
            int m = root->children.size();
            auto curr = ans->left;
            for (int i = 1; i < m; ++i) {
                curr->right = encode(root->children[i]);
                curr = curr->right;
            }
        }
        return ans;
    }
	
    // Decodes your binary tree to an n-ary tree.
    Node* decode(TreeNode* root) {
        if (!root)
            return nullptr;
        Node* ans = new Node(root->val);
        if (root->left) {
            ans->children.push_back(decode(root->left));
            auto curr = root->left;
            while (curr->right) {
                ans->children.push_back(decode(curr->right));
                curr = curr->right;
            }
        }            
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(root));