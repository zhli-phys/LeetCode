class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        else if ((p && !q) || (q && !p))
            return false;
        else
            return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};