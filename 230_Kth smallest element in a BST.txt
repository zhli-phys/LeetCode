class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int rank = 0;
        int ans;
        bool found = false;
        findrank(root, k, rank, ans, found);
        return ans;
    }
    
    void findrank(TreeNode* root, int k, int& rank, int& ans, bool& found) {
        if (!root)
            return;
        if (found)
            return;
        findrank(root->left, k, rank, ans, found);
        rank++;
        if (rank == k) {
            ans = root->val;
            found = true;
        }
        findrank(root->right, k, rank, ans, found);
    }
};