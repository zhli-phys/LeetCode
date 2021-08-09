class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = inorder.size();
        if (len == 0)
            return NULL;
        unordered_map<int, int> inorder_index;
        for (int i = 0; i < len; i++) {
            inorder_index.insert(pair<int, int>(inorder[i], i));
        }
        return buildTree(preorder, inorder_index, 0, len, 0);
    }
    
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int>& inorder_index, int left, int right, int inorder_left) {
        if (left == right)
            return NULL;
        int value = preorder[left];
        TreeNode* root = new TreeNode(value);
        int index = inorder_index[value] - inorder_left + left;
        root->left = buildTree(preorder, inorder_index, left + 1, index + 1, inorder_left);
        root->right = buildTree(preorder, inorder_index, index + 1, right, inorder_index[value] + 1);
        return root;
    }
};










//O(n^2) 68 ms 8%; 26 MB 64%
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return build_tree(0, n, preorder, 0, n, inorder);
    }
    
    TreeNode* build_tree(int pl, int pr, vector<int>& preorder, int il, int ir, vector<int>& inorder) {
        if (pl == pr)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pl]);
        if (pr == pl + 1)
            return root;
        int im = il;
        while (inorder[im] != preorder[pl])
            ++im;
        root->left = build_tree(pl + 1, pl + im - il + 1, preorder, il, im, inorder);
        root->right = build_tree(pr - ir + im + 1, pr, preorder, im + 1, ir, inorder);
        return root;
    }
};












//hash table; O(n) 36 ms 31%; 26.4 MB 34%
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        unordered_map<int, int> pos;
        for (int i = 0; i < n; ++i)
            pos[inorder[i]] = i;
        return build_tree(0, n, preorder, 0, n, pos);
    }
    
    TreeNode* build_tree(int pl, int pr, vector<int>& preorder, int il, int ir, unordered_map<int, int>& pos) {
        if (pl == pr)
            return NULL;
        TreeNode* root = new TreeNode(preorder[pl]);
        if (pr == pl + 1)
            return root;
        int im = pos[preorder[pl]];
        root->left = build_tree(pl + 1, pl + im - il + 1, preorder, il, im, pos);
        root->right = build_tree(pr - ir + im + 1, pr, preorder, im + 1, ir, pos);
        return root;
    }
};