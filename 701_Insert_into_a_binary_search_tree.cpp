class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        TreeNode* parent = nullptr;
        auto curr = root;
        while (curr) {
            parent = curr;
            if (curr->val > val)
                curr = curr->left;
            else
                curr = curr->right;
        }
        if (parent->val > val)
            parent->left = new TreeNode(val);
        else
            parent->right = new TreeNode(val);
        return root;
    }
};











class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root)
            return new TreeNode(val);
        if (root->val > val) 
            root->left = insertIntoBST(root->left, val);
        else 
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};