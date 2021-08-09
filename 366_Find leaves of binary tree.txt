//O(n) 0 ms 100%; O(n) 9.4 MB 9%
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<TreeNode*, int> level;
        build_level(root, level);
        vector<vector<int>> ans(level[root]);
        preorder(root, level, ans);
        return ans;
    }
    
    int build_level(TreeNode* root, unordered_map<TreeNode*, int>& level) {
        if (!root)
            return 0;
        level[root] = max(build_level(root->left, level), build_level(root->right, level)) + 1;
        return level[root];
    }
    
    void preorder(TreeNode* root, unordered_map<TreeNode*, int>& level, vector<vector<int>>& ans) {
        if (!root)
            return;
        ans[level[root]-1].push_back(root->val);
        preorder(root->left, level, ans);
        preorder(root->right, level, ans);
    }
};









//no extra space; 0 ms 100%; 9 MB 42%
class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> ans;
        level(root, ans);
        return ans;
    }
    
    int level(TreeNode* root, vector<vector<int>>& ans) {
        if (!root)
            return -1;
        int pos = max(level(root->left, ans), level(root->right, ans)) + 1;
        if (ans.size() <= pos)
            ans.push_back({root->val});
        else
            ans[pos].push_back(root->val);
        return pos;
    }
};