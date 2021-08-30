class Solution {
public:
    bool checkEqualTree(TreeNode* root) {
        int totalSum = treeSum(root);
        if (totalSum % 2 != 0)
            return false;
        bool ans = false;
        check(root->left, totalSum / 2, ans);
        check(root->right, totalSum / 2, ans);
        return ans;
    }
    
    int treeSum(TreeNode* root) {
        if (!root)
            return 0;
        return root->val + treeSum(root->left) + treeSum(root->right);
    }
    
    int check(TreeNode* root, int targetSum, bool& ans) {
        if (!root)
            return 0;
        int currSum = root->val + check(root->left, targetSum, ans) + check(root->right, targetSum, ans);
        if (currSum == targetSum)
            ans = true;
        return currSum;
    }
};