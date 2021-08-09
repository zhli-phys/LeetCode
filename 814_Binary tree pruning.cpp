class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (!root)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->val == 0 && !root->left && !root->right)
            return NULL;
        return root;
    }
};










class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        unordered_map<TreeNode*, bool> zero;
        if (allZero(root, zero))
            return NULL;
        return prune(root, zero);
    }
    
    TreeNode* prune(TreeNode* root, unordered_map<TreeNode*, bool>& zero) {
        if (!root)
            return NULL;
        if (allZero(root->left, zero))
            root->left = NULL;
        else
            prune(root->left, zero);
        if (allZero(root->right, zero))
            root->right = NULL;
        else
            prune(root->right, zero);
        return root;
    }
    
    bool allZero(TreeNode* root, unordered_map<TreeNode*, bool>& zero) {
        if (!root)
            return true;
        if (root->val != 0)
            return false;
        if (zero.find(root) != zero.end())
            return zero[root];
        zero[root] = allZero(root->left, zero) && allZero(root->right, zero);
        return zero[root];
    }
};