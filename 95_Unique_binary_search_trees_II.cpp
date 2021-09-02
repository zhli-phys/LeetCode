class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> dp(n + 1);
        dp[0].push_back(NULL);
        dp[1].push_back(new TreeNode(1));
        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                int n1 = dp[j - 1].size();
                int n2 = dp[i - j].size();
                for (int k = 0; k < n1; ++k) {
                    for (int l = 0; l < n2; ++l) {
                        TreeNode* curr = new TreeNode(j);
                        curr->left = replicate(dp[j-1][k], 0);
                        curr->right = replicate(dp[i-j][l], j);
                        dp[i].push_back(curr);
                    }
                }
            }
        }
        return dp[n];
    }
    
    TreeNode* replicate(TreeNode* origin, int base) {
        if (!origin)
            return NULL;
        TreeNode* curr = new TreeNode(origin->val + base);
        curr->left = replicate(origin->left, base);
        curr->right = replicate(origin->right, base);
        return curr;
    }
};