class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        if (!root)
            return nullptr;
        return helper(root).first;
    }
    
    pair<TreeNode*, TreeNode*> helper(TreeNode* root) {
        pair<TreeNode*, TreeNode*> ans = {root, root};
        if (root->left) {
            auto leftPair = helper(root->left);
            ans.first = leftPair.first;
            leftPair.second->right = root;
            root->left = nullptr;
        }        
        if (root->right) {
            auto rightPair = helper(root->right);
            root->right = rightPair.first;
            ans.second = rightPair.second;
        }
        return ans;
    }
};