class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i)
            mp[inorder[i]] = i;
        return build(0, n - 1, inorder, 0, n - 1, postorder, mp);
    }
    
    TreeNode* build(int il, int ir, vector<int>& inorder,
                   int pl, int pr, vector<int>& postorder, unordered_map<int, int>& mp) {
        if (il > ir)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[pr]);
        int pos = mp[postorder[pr]];
        root->left = build(il, pos - 1, inorder, pl, pl + pos - il - 1, postorder, mp);
        root->right = build(pos + 1, ir, inorder, pr - ir + pos, pr - 1, postorder, mp);
        return root;
    }
};