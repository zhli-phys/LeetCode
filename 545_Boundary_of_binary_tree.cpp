class Solution {
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> boundary;
        boundary.push_back(root->val);
        if (root->left) {
            leftBoundary(root->left, boundary);
            leafs(root->left, boundary);
        }
        vector<int> rb;
        if (root->right) {
            rightBoundary(root->right, rb);
            leafs(root->right, boundary);
        }
        reverse(rb.begin(), rb.end());
        boundary.insert(boundary.end(), rb.begin(), rb.end());
        return boundary;
    }
    
    void leftBoundary(TreeNode* curr, vector<int>& boundary) {
        boundary.push_back(curr->val);
        if (curr->left)
            leftBoundary(curr->left, boundary);
        else if (curr->right)
            leftBoundary(curr->right, boundary);
        else
            boundary.pop_back();
    }
    
    void leafs(TreeNode* curr, vector<int>& boundary) {
        if (!curr->left && !curr->right)
            boundary.push_back(curr->val);
        if (curr->left)
            leafs(curr->left, boundary);
        if (curr->right)
            leafs(curr->right, boundary);
    }
    
    void rightBoundary(TreeNode* curr, vector<int>& rb) {
        rb.push_back(curr->val);
        if (curr->right)
            rightBoundary(curr->right, rb);
        else if (curr->left)
            rightBoundary(curr->left, rb);
        else
            rb.pop_back();
    }
};