class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int curr = 0;
        int ans = 0;
        dfs(root, curr, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int& curr, int& ans) {
        if (!root)
            return;
        curr = 10 * curr + root->val;
        if (!root->left && !root->right) 
            ans += curr;
        else {
            dfs(root->left, curr, ans);
            dfs(root->right, curr, ans);
        }
        curr /= 10;
    }
};