class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        unordered_map<int, int> path;
        path[0] = 1;
        dfs(root, path, 0, targetSum, ans);
        return ans;
    }
    
    void dfs(TreeNode* root, unordered_map<int, int>& path, int currSum, int targetSum, int& ans) {
        if (!root)
            return;
        currSum += root->val;
        if (path.find(currSum - targetSum) != path.end())
            ans += path[currSum - targetSum];
        ++path[currSum];
        dfs(root->left, path, currSum, targetSum, ans);
        dfs(root->right, path, currSum, targetSum, ans);
        --path[currSum];
        if (path[currSum] == 0)
            path.erase(currSum);
    }
};













class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<TreeNode*, unordered_map<int, int>> paths;
        return pathSum(root, sum, paths);
    }
    
    int pathSum(TreeNode* root, int sum, unordered_map<TreeNode*, unordered_map<int, int>>& paths) {
        if (!root)
            return 0;
        int ans = pathSum(root->left, sum, paths) + pathSum(root->right, sum, paths)
                    + pathwithroot(root->left, sum - root->val, paths)
                    + pathwithroot(root->right, sum - root->val, paths);
        if (sum == root->val)
            ans++;
        return ans;
    }
    
    int pathwithroot(TreeNode* root, int sum, unordered_map<TreeNode*, unordered_map<int, int>>& paths) {
        if (!root) 
            return 0;
        unordered_map<TreeNode*, unordered_map<int, int>>::iterator it = paths.find(root);
        if (it != paths.end()) {
            if (it->second.find(sum) != it->second.end())
                return it->second[sum];
        }
        int ans = pathwithroot(root->left, sum - root->val, paths) 
                    + pathwithroot(root->right, sum - root->val, paths);
        if (sum == root->val)
            ans++;
        paths[root][sum] = ans;
        return ans;
    }
};








class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        vector<int> currsum;
        return pathSum(root, sum, currsum);
    }
    
    int pathSum(TreeNode* root, int sum, vector<int>& currsum) {
        int count = 0;
        for (int i = 0; i < currsum.size(); i++) {
            currsum[i] += root->val;
            if (currsum[i] == sum)
                count++;
        }
        currsum.push_back(root->val);
        if (sum == root->val)
            count++;
        if (root->left)
            count += pathSum(root->left, sum, currsum);
        if (root->right)
            count += pathSum(root->right, sum, currsum);
        currsum.pop_back();
        for (int i = 0; i < currsum.size(); i++)
            currsum[i] -= root->val;
        return count;
    }
};