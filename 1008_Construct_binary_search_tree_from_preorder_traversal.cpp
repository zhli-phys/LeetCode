// O(n)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(i, INT_MIN, INT_MAX, preorder);
    }
    
    TreeNode* build(int& i, int lowerLimit, int upLimit, vector<int>& preorder) {
        if (i >= preorder.size())
            return nullptr;
        if (preorder[i] < lowerLimit || preorder[i] > upLimit) 
            return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);
        ++i;
        root->left = build(i, lowerLimit, root->val, preorder);
        root->right = build(i, root->val, upLimit, preorder);
        return root;
    }
};








// O(n^2)
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size();
        return build(0, n - 1, preorder);
    }
    
    TreeNode* build(int i, int j, vector<int>& preorder) {
        if (i > j)
            return nullptr;
        TreeNode* root = new TreeNode(preorder[i]);
        int next = i + 1;
        while (next <= j && preorder[next] < preorder[i])
            ++next;
        root->left = build(i + 1, next - 1, preorder);
        root->right = build(next, j, preorder);
        return root;
    }
};