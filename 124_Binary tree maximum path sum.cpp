class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if (!root)
            return 0;
        return maxSum(root);
    }
    
    int maxSum(TreeNode* root) {
        int result = throughtRootMax(root);
        if (root->left)
            result = max(result, maxSum(root->left));
        if (root->right)
            result = max(result, maxSum(root->right));
        return result;
    }
    
    int throughtRootMax(TreeNode* root) {
        int left = max(oneLineMax(root->left), 0);
        int right = max(oneLineMax(root->right), 0);
        return root->val + left + right;
    }
    
    int oneLineMax(TreeNode* root) {
        if (!root)
            return 0;
        unordered_map<TreeNode*, int>::iterator it = onelinemax.find(root);
        if (it != onelinemax.end())
            return onelinemax[root];
        int left = max(oneLineMax(root->left), 0);
        int right = max(oneLineMax(root->right), 0);
        int result =  root->val + max(left, right);
        onelinemax.insert(pair<TreeNode*, int>(root, result));
        return result;
    }
    
private:
    unordered_map<TreeNode*, int> onelinemax;
};