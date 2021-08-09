//dfs; 12 ms 60%; 20 MB 61%
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, 0, targetSum, path, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, int currSum, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) 
            return;
        else {
            path.push_back(root->val);
            currSum += root->val;
            if (!root->left && !root->right) {
                if (currSum == targetSum)
                    ans.push_back(path);
            }
            else {
                dfs(root->left, currSum, targetSum, path, ans);
                dfs(root->right, currSum, targetSum, path, ans);
            }
            currSum -= root->val;
            path.pop_back();
        }
    }
};