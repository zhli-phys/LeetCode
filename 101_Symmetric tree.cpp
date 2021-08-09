class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return mirror(root->left, root->right);
    }
    
    bool mirror(TreeNode* left, TreeNode* right) {
        if (!left && !right)
            return true;
        if (!left || !right)
            return false;
        if (left->val == right->val && mirror(left->left, right->right) && mirror(left->right, right->left))
            return true;
        else
            return false;
    }
};