class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root)
            return 0;
        int ans = 0;
        if (root->val >= L && root->val <= R)
            ans += root->val;
        if (root->val < R)
            ans += rangeSumBST(root->right, L, R);
        if (root->val > L)
            ans += rangeSumBST(root->left, L, R);
        return ans;
    }
};






class Solution {
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        TreeNode* curr = root;
        int ans = 0;
        stack<TreeNode*> sk;
        sk.push(root);
        while (!sk.empty()) {
            curr = sk.top();
            sk.pop();
            if (curr->val >= L && curr->val <= R)
                ans += curr->val;
            if (curr->val > L && curr->left)
                sk.push(curr->left);
            if (curr->val < R && curr->right)
                sk.push(curr->right);
        }
        return ans;
    }
};