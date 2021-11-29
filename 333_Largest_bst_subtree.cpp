struct bst{
    int num;
    int lowerBound;
    int upperBound;
    bst(int num) : num(num), lowerBound(INT_MAX), upperBound(INT_MIN) { }
};

class Solution {
public:
    int largestBSTSubtree(TreeNode* root) {
        int ans = 0;
        explore(root, ans);
        return ans;
    }
    
    bst explore(TreeNode* root, int& ans) {
        if (!root)
            return bst(0);
        auto leftBST = explore(root->left, ans);
        auto rightBST = explore(root->right, ans);
        bst output(-1);
        if (leftBST.num >= 0 && rightBST.num >= 0 && 
            root->val > leftBST.upperBound && root->val < rightBST.lowerBound) {
            output.num = leftBST.num + rightBST.num + 1;
            ans = max(ans, output.num);
            output.lowerBound = min(leftBST.lowerBound, root->val);
            output.upperBound = max(rightBST.upperBound, root->val);
            
        }
        return output;
    }
};