class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        dfs(root, 0, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int curr, int& ans) {
        curr = 2 * curr + root->val;
        if (!root->left && !root->right) 
            ans += curr;
        else {
            if (root->left)
                dfs(root->left, curr, ans);
            if (root->right)
                dfs(root->right, curr, ans);
        }
    }
};