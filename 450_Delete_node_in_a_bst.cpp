class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root)
            return nullptr;
        if (root->val == key)
            return update(root, key);
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
            return root;
        }
        else {
            root->left = deleteNode(root->left, key);
            return root;
        }
    }
    
    TreeNode* update(TreeNode* root, int key) {
        if (!root->right)
            return root->left;
        TreeNode* newRoot = nullptr;
        TreeNode* newRight = removeMostLeft(root->right, newRoot);
        newRoot->right = newRight;
        newRoot->left = root->left;
        return newRoot;
    }
    
    TreeNode* removeMostLeft(TreeNode* root, TreeNode*& newRoot) {
        if (!root->left) {
            newRoot = root;
            return root->right;
        }
        else {
            root->left = removeMostLeft(root->left, newRoot);
            return root;
        }
    }
};