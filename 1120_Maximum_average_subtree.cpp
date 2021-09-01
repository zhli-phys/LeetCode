class Solution {
public:
    double maximumAverageSubtree(TreeNode* root) {
        double maxAvg = 0.0;
        search(root, maxAvg);
        return maxAvg;
    }
    
    pair<int, double> search(TreeNode* root, double& maxAvg) {
        if (!root)
            return {0, 0.0};
        auto leftPair = search(root->left, maxAvg);
        auto rightPair = search(root->right, maxAvg);
        int currSize = 1 + leftPair.first + rightPair.first;
        double currAvg = (root->val + leftPair.first * leftPair.second 
                          + rightPair.first * rightPair.second) / currSize;
        maxAvg = max(maxAvg, currAvg);
        return {currSize, currAvg};
    }
};