/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root)
            return NULL;
        TreeNode* temp;
        if (root->val < p->val)
            return inorderSuccessor(root->right, p);
        else if (root->val > p->val) {
            TreeNode* temp = inorderSuccessor(root->left, p);
            if (temp)
                return temp;
            else
                return root;
        }
        else {
            TreeNode* temp = smallest(root->right);
            if (temp)
                return temp;
            else 
                return NULL;            
        }
    }
    
    TreeNode* smallest(TreeNode* root) {
        if (!root)
            return NULL;
        TreeNode* temp = smallest(root->left);
        if (temp)
            return temp;
        else
            return root;
    }
};