class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        if (depth(root, x) == depth(root, y) && !samePar(root, x, y))
            return true;
        else
            return false;
    }
    
    int depth(TreeNode* root, int x) {
        if (!root)
            return 10000;
        if (root->val == x)
            return 0;
        else
            return min(depth(root->left, x), depth(root->right, x)) + 1;
    }
    
    bool samePar(TreeNode* root, int x, int y) {
        if (!root)
            return false;
        if (!root->left)
            return samePar(root->right, x, y);
        else if (!root->right)
            return samePar(root->left, x, y);
        else if ((root->left->val == x && root->right->val == y)
                 || (root->right->val == x && root->left->val == y))
            return true;
        else
            return samePar(root->left, x, y) || samePar(root->right, x, y);
    }
};