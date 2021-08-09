class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, int> lfr;
        return largestlength(root, lfr);
    }
    
    int largestlength(TreeNode* root, unordered_map<TreeNode*, int>& lfr) {
        if (!root)
            return 0;
        int a[3];
        a[0] = largestlength(root->left, lfr);
        a[1] = largestlength(root->right, lfr);
        a[2] = 2 + lengthfromroot(root->left, lfr) + lengthfromroot(root->right, lfr);
        int ans = *max_element(a, a + 3);
        return ans;
    }
    
    int lengthfromroot(TreeNode* root, unordered_map<TreeNode*, int>& lfr) {
        if (!root)
            return -1;
        if (lfr.find(root) != lfr.end())
            return lfr[root];
        int left = 1 + lengthfromroot(root->left, lfr);
        int right = 1 + lengthfromroot(root->right, lfr);
        int ans = max(left, right);
        lfr[root] = ans;
        return ans;
    }
};