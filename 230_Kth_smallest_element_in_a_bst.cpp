class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int currRank = 0;
        return explore(root, currRank, k);
    }
    
    int explore(TreeNode* root, int& currRank, int k) {
        if (!root)
            return -1;
        int leftNum = explore(root->left, currRank, k);
        if (currRank >= k)
            return leftNum;
        ++currRank;
        if (currRank == k)
            return root->val;
        else 
            return explore(root->right, currRank, k);
    }
};