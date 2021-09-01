class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;
        int minDep = INT_MAX;
        search(root, 1, minDep);
        return minDep;
    }
    
    void search(TreeNode* root, int currDep, int& minDep) {
        if (!root->left && !root->right) 
            minDep = min(currDep, minDep);           
        if (root->left)
            search(root->left, currDep + 1, minDep);
        if (root->right)
            search(root->right, currDep + 1, minDep);
    }
};