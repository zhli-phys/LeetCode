class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int h = height(root);
        cout << h << endl;
        return (1 << (h - 1)) + bst(1, (1 << (h - 1)), h, root) - 1;
    }
    
    int height(TreeNode* root) {
        if (!root)
            return 0;
        return height(root->left) + 1;
    }
    
    int bst(int left, int right, int h, TreeNode* root) {
        if (left == right)
            return left;
        int mid = (left + right + 1) / 2;
        auto curr = root;
        for (int i = 1; i < h; ++i) {
            if (mid <= (1 << (h - i - 1))) {
                curr = curr->left;
            }                
            else {
                curr = curr->right;
                mid -= (1 << (h - i - 1));
            }
        }
        mid = (left + right + 1) / 2;
        if (curr) 
            return bst(mid, right, h, root);
        else
            return bst(left, mid - 1, h, root);
    }
};