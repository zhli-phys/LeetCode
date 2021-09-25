class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root, 0);
        return root;
    }
    
    int convert(TreeNode* root, int preSum) {
        if (!root)
            return preSum;
        int ans = convert(root->right, preSum) + root->val;
        root->val = ans;
        return convert(root->left, ans);
    }
};