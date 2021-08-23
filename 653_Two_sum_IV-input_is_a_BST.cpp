class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root)
            return false;
        if (k > 2 * root->val && (contain(root->right, k - root->val) || findTarget(root->right, k)))
            return true;
        if (k < 2 * root->val && (contain(root->left, k - root->val) || findTarget(root->left, k)))
            return true;
        if (conjugate(root->left, root->right, k))
            return true;
        return false;
    }
    
    bool contain(TreeNode* root, int k) {
        if (!root)
            return false;
        if (root->val == k)
            return true;
        else if (root->val > k)
            return contain(root->left, k);
        else
            return contain(root->right, k);
    }
    
    bool conjugate(TreeNode* leftNode, TreeNode* rightNode, int k) {
        if (!leftNode || !rightNode)
            return false;
        int sum = leftNode->val + rightNode->val;
        if (sum == k)
            return true;
        else if (sum > k) 
            return conjugate(leftNode->left, rightNode, k) || conjugate(leftNode, rightNode->left, k);
        else
            return conjugate(leftNode->right, rightNode, k) || conjugate(leftNode, rightNode->right, k);
    }
};