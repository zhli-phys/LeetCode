class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return helper(root);
    }
    
    bool helper(TreeNode* root, bool left = false, int min = INT_MIN, bool right = false, int max = INT_MAX) {
        if (!root)
            return true;
        if ((left && root->val <= min) || (right && root->val >= max))
            return false;
        if (helper(root->left, left, min, true, root->val) && helper(root->right, true, root->val, right, max))
            return true;
        else
            return false;
    }
};