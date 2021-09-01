class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        dfs(root, to_string(root->val), ans);
        return ans;
    }
    
    void dfs(TreeNode* root, string curr, vector<string>& ans) {
        if (!root->left && !root->right)
            ans.push_back(curr);
        if (root->left) 
            dfs(root->left, curr + "->" + to_string(root->left->val), ans);
        if (root->right) 
            dfs(root->right, curr + "->" + to_string(root->right->val), ans);
    }
};